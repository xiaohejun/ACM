/**
* 数字三角形求最优路径
* 时间复杂度(2^n)
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


#define Max 101
int D[Max][Max]; // 二维数组放数字

// 从数组D的i行j列数字开始走到第n行的最优路径
int MaxSum(int i, int j, int n) {
	if ( i == n) { // 如果起点行数和终点行数相同
		return D[i][j]; // 返回当前这个点
	}
	int x = MaxSum(i+1, j, n); // 左下角的点开始的最优路径
	int y = MaxSum(i+1, j+1, n); // 右下角的点开始的最优路径
	return max(x,y) + D[i][j]; // 左下角走和右下角左取最大的哪一个加上自己的值
}

int main(int argc, char const *argv[])
{	
	int n;
	cin >> n; // 输入三角形的行数
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> D[i][j]; // 输入三角形
		}
	} // 输入结束
	cout << MaxSum(1,1,n) << endl;
	return 0;
}
