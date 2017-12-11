/**
* 输出前m大的数字
* 该方法会超时
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int a[100000];

// 交换两个数
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void print(int *a, int src, int dest) {
	while (src++ <= dest) {
		cout << a[src-1] << endl;
	}
}
// 时间复杂度
// O(nlogn ^ nlongn)
// 把前k大的数移动到数组右边
void arrangeRight(int *a, int src, int dest, int k) {
	if (src >= dest) {
		return;
	}
	int key = a[src]; // 一开始key定于第一个
	int pl = src, pr = dest;
	while (pl != pr) {
		while (pl < pr && a[pr] <= key) pr--;
		swap(a[pr], a[pl]);
		while (pl < pr && a[pl] >= key) pl++;
		swap(a[pr], a[pl]);
	}
	arrangeRight(a, src, pr - 1, 0); // 前半部分
	arrangeRight(a, pr + 1, dest, 0); // 后半部分
	if ( k != 0) {
		int num = dest - pl; // 从key到最后有多少个数字
		if (num > k) { // 如果数字数目大于要的数字
			arrangeRight(a, pl + 1, dest, k); // 对于右边再移动k个到右边
		}
		if (num < k) { // 如果数字数目小于要的数字
			arrangeRight(a, src, pr, k - num); // 对左边再移动k-num个 
		}
	}
	return;
}



int main(int argc, char const *argv[])
{	
	int n,i,k;
	while (cin >> n && n < 100000) {
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> k;
		arrangeRight(a, 0, n-1, k); // 把第k大的数移动到右边，并且排序
		print(a, 0, k-1); // 打印
	}
	return 0;
}
