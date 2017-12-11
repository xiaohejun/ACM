#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;  

const int MAX_P = 1e6+10;
int a[MAX_P];
int P;

void solve(){ // 尺取法
	set<int> all; // 记录知识点的类型
	for (int i = 0; i < P; ++i) all.insert(a[i]);
	int n = all.size(); // 记录知识点的个数
	
	int res = P; // 开始设置成最大值
	int s = 0, t = 0, num = 0;
	map<int, int> count; // i号知识点出现的次数
	while(true) {
	    while(t < P && num < n) { // 所有知识点都包含的子区间,右边端点固定
	        if (count[a[t++]]++ == 0) num++;// 出现新的知识点,并且在这个区间知识点的次数加1
	    }
	    if(num < n) break; // 保证数据的正确性
	    res = min(res, t-s); // 更新res
	    if (--count[a[s++]] == 0) num--; // 知识点为0了.不包含了
	}
	printf("%d\n", res);
}


int main(int argc, char const *argv[])
{	
	//freopen("JessicaReadingProblem.txt", "r", stdin);
	while(cin >> P) {
	    for (int i = 0; i < P; ++i)
	    {
	    	scanf("%d", &a[i]);
	    }
	    solve();
	}
	return 0;
}