/**
* 数字三角形记忆递归型动归
* 时间复杂度(n^2)
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


#define Max 101
int D[Max][Max]; // 二维数组放数字
int maxSum[Max][Max]; // 存放每一个节点得maxSum值

// 从数组D的i行j列数字开始走到第n行的最优路径
int MaxSum(int i, int j, int n) {
	if (maxSum[i][j] != -1) {
		return maxSum[i][j]; // 不是初始值，说明计算出来了，直接返回，防止重复计算
	}
	if ( i == n) { // 如果起点行数和终点行数相同
		maxSum[i][j] = D[i][j]; // 返回当前这个点
	}
	else {
		int x = MaxSum(i + 1, j, n); // 左下角的点开始的最优路径
		int y = MaxSum(i + 1, j + 1, n); // 右下角的点开始的最优路径
		maxSum[i][j] = max(x, y) + D[i][j]; // 左下角走和右下角左取最大的哪一个加上自己的值
	}
	return maxSum[i][j];
}

int main(int argc, char const *argv[])
{	
	int n;
	cin >> n; // 输入三角形的行数
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> D[i][j]; // 输入三角形
			maxSum[i][j] = -1; // 把每一个节点的maxSum值初始化成-1
		}
	} // 输入结束
	cout << MaxSum(1,1,n) << endl;
	return 0;
}
