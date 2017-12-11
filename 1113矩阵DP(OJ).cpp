#include "stdafx.h"
/*
1113: 矩阵DP(OJ)
*/

#include <iostream>
#include <algorithm>
using namespace std;


const int max_m = 15;
const int max_n = 15;
int matrix[max_m][max_n]; // 矩阵
int M, N;

int main()
{
	freopen("in.txt", "r", stdin);
	while (cin >> M >> N && M && N)
	{	
		int DP[max_m][max_n] = {0}; // 设DP(x,y)表示从左上角(1,1)开始到达(x,y)格时价值总和的最小值
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> matrix[i][j]; // 输入数据
			}
		}
		// 计算
		/*
		设f(x,y)表示从左上角(1,1)开始到达(x,y)格时价值总和的最小值。map[i,j]表示格中的价值数。
动态规划方程：f(x,y)=min{f(x-1,y),f(x,y-1)}+map(x,y);(1<x,y<=n)

边界条件1：f(1,y)=f(1,y-1)+map(1,y);(1<y<=n)
          f(x,1)=f(x-1,1)+map(x,1);(1<x<=n)
          f(1,1)=map(1,1)
边界条件2：f(0,y)=0;(1<=y<=n)
           f(x,0)=0;(1<=x<=n)
		*/
		// 边界条件
		for (int i = 1; i <= N; i++) {
			DP[1][i] = DP[1][i-1] + matrix[1][i];
		}
		for (int i = 1; i <= M; i++) {
			DP[i][1] = DP[i-1][1] + matrix[i][1];
		}
		DP[1][1] = matrix[1][1];
		for (int i = 2; i <= M; i++) {
			for (int j = 2; j <= N; j++) {
				DP[i][j] = min(DP[i-1][j], DP[i][j-1])+matrix[i][j];
			}
		}
		if (DP[M][N] > 0) {
			cout << DP[M][N] << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	fclose(stdin);
	return 0;
}
