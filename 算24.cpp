/**
* -----算24--------
*	给出4个小于10的整数,用加减乘除括号组合之后得到一个表达式
*  这个表达式的值是24
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

#define Eps 1e-6

// 判断一个双精度数是不是0
bool isZero(double d) {
	return fabs(d) <= Eps;
}

// 用数组里的n个数计算结果是不是24
bool count24(double a[], int n) {
	// 边界条件,当只有一个数字的时候
	if (n == 1) {
		return isZero(a[0] - 24);
	}
	// 有不止一个数
	double b[5]; // 开辟一个数组用于存放剩下的数
	for (int i = 0; i < n - 1; i++) { // 枚举数组中的所有两个数字个可能组合
		for (int j = i + 1; j < n; j++) {
			int m = 0;
			// 把剩下的n-2个数放在数组b中
			for (int k = 0; k < n; k++) {
				if (k!=i && k!=j) {
					b[m++] = a[k];
				}
			}
			// 对拿出来的两数进行操作
			// +操作
			b[m] = a[i] + a[j]; // 把结果得到的数放在b数组中
			if (count24(b, m+1)) { // 剩下的计算是24的话
				return true;
			}
			// - 操作
			b[m] = a[i] - a[j]; // 把结果得到的数放在b数组中
			if (count24(b, m + 1)) { // 剩下的计算是24的话
				return true;
			}
			// -操作第二种情况
			b[m] = a[j] - a[i]; // 把结果得到的数放在b数组中
			if (count24(b, m + 1)) { // 剩下的计算是24的话
				return true;
			}
			// *的操作
			b[m] = a[j] * a[i]; // 把结果得到的数放在b数组中
			if (count24(b, m + 1)) { // 剩下的计算是24的话
				return true;
			}
			// /的操作
			if (!isZero(a[i])) {
				b[m] = a[j] / a[i]; // 把结果得到的数放在b数组中
				if (count24(b, m + 1)) { // 剩下的计算是24的话
					return true;
				}
			}
			// /的操作第二种情况
			if (!isZero(a[j])) {
				b[m] = a[i] / a[j]; // 把结果得到的数放在b数组中
				if (count24(b, m + 1)) { // 剩下的计算是24的话
					return true;
				}
			}
		}
	}
	// 各种操作都不满足，就返回false
	return false;
}

int main()
{	
	int flag = 0;
	double a[5];
	while (1)
	{
		for (int i = 0; i < 4; i++) {
			cin >> a[i];
			a[i] ? flag = 0 : flag++;
		}
		if (flag == 4) {
			break;
		}
		if (count24(a, 4)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}