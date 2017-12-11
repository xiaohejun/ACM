/**
* 数字三角形递推实现(时间优化加上空间优化)
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


#define Max 101
int D[Max][Max]; // 二维数组放数字
int * maxSum; // 存放每一行节点的maxSum值

int main(int argc, char const *argv[])
{	
	int n;
	cin >> n; // 输入三角形的行数
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> D[i][j]; // 输入三角形
		}
	} // 输入结束
	maxSum = D[n]; // 最后一行的maxSum值就是本身
	for (int i = n-1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			maxSum[j] = max(maxSum[j], maxSum[j+1]) + D[i][j]; // 从下往上递推
		}
	} // 计算结束
	cout << maxSum[1] << endl;
	return 0;
}
