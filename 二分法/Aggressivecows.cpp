/**********************************

	利用二分法最大化最小值

**********************************/

#include <bits/stdc++.h>
using namespace  std;


const int MAX_N = 100000+10;
const int INF = 1000000000+10;

int x[MAX_N]; // 牛圈在的位置
int N,M; // N个牛圈,C个牛

bool C(int d){ // 如果距离是d可以满足把牛安排完,返回true
	int last = 0, ctx = 0; // 后面的位置,一开始把第一头牛安排在x[0]  
	for (int i = 1; i < M; ++i) // 安排M-1头牛
	{	
		ctx = last+1;
		while(ctx < N && x[ctx] - x[last] < d) ctx++; // 向后安排
		if(ctx >= N) return false; // 不可以安排完
		last = ctx;
	}
	return true; // 牛都可以安排完
}

void solve(){ // 最大化最小值
	sort(x, x+N); // 将数组的值从小到大排序
	int lb = 0, ub = INF;
	while(ub - lb > 1) {
	    int mid = (lb+ub)/2;
	    if (C(mid)) // 如果满足条件
	    {
	    	lb = mid; // 值还可以大
	    } else { 
	    	ub = mid; // 值要小
	    }
	}
	printf("%d\n", lb); // 输出结果
}

int main(int argc, char const *argv[])
{
	//freopen("Aggressivecows.txt", "r", stdin);
	while(cin >> N >> M) { // 输入数据
	    for (int i = 0; i < N; ++i)
	    {
	    	scanf("%d", &x[i]);
	    }
	    solve(); 
	}
	//fclose(stdin);
	return 0;
}
