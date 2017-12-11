#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;  

const int MAX_N =  100000+10;
int a[MAX_N];
int N,S,T;

void solve(){ // 尺取法
	int res = N+1; // res的值用于更新
	int s = 0, t = 0, sum = 0;
	while(true) {
	    while(t < N && sum < S) { // 尺子右端向后移动 
	        sum += a[t++];
	    }
	    if(sum < S) break; // 序列全部加完都不能满足
	    res = min(res, t-s); // 更新res的值
	    sum -= a[s++]; // 尺子左端向前移动
	}
	if(res > N) res = 0;
	printf("%d\n", res);
}


int main(int argc, char const *argv[])
{	
	//freopen("Subsequence.txt", "r", stdin);
	cin >> T;
	while(T--) {
	    cin >> N >> S;
	    for (int i = 0; i < N; ++i)
	    {
	    	scanf("%d", &a[i]);
	    }
	    solve();
	}
	return 0;
}