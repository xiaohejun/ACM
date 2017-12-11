/**
 * 递归到动规的一般转化方法
 * 递归函数有n个参数，就定义一个n维的数组，
 * 数组的下标是递归函数参数的取值范围
 * 
 * 动规解题的一般思路
 * 
 */

/**
* 最长上升子序列（“人人为我递归型动归程序”）
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


const int MaxN = 1010;
int a[MaxN]; // 装数组序列
int maxLen[MaxN]; // 以该位置为终点的最长上升序列长度


int main(int argc, char const *argv[])
{	
	int n;
	cin >> n; // 输入序列的个数
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; // 输入序列
		maxLen[i] = 1; // 初始化最长上升数列的值是1，也就是当只有他一个数字的时候
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) { // 从一开始，找前面的比它小的数
			if ( a[i] > a[j]) {
				maxLen[i] = max(maxLen[i], maxLen[j]+1); // 存比较大的那一个数
			}
		}
	}
	cout << * max_element(maxLen+1, maxLen+n+1) << endl; // 寻找从1到n的最大元素
	return 0;
}
