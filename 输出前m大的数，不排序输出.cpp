/**
* 输出前m大的数字
* 排序后输出：复杂度O()
* 用分治处理：复杂度O(n+mlogm)
* 思路用O(n)的时间复杂度把前m大的数移动到数组右边，对
* 右边的m个数字排序再输出
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int a[] = { 4,8,9,10,6,7,1,3,2,5 };

// 交换两个数
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void print(int *a, int src, int dest) {
	while (src++ <= dest) {
		cout << a[src-1] << " ";
	}
	cout << "\n";
}
// 把前k大的数移动到数组右边
void arrangeRight(int *a, int src, int dest, int k) {
	if (src > dest) {
		return;
	}
	int key = a[src]; // 一开始key定于第一个
	int pl = src, pr = dest;
	while (pl != pr) {
		while (pl < pr && a[pr] >= key) pr--;
		swap(a[pr], a[pl]);
		while (pl < pr && a[pl] <= key) pl++;
		swap(a[pr], a[pl]);
	}
	int num = dest - pl; // 从key到最后有多少个数字
	if (num > k) { // 如果数字数目大于要的数字
		arrangeRight(a, pl+1, dest, k); // 对于右边再移动k个到右边
	}
	if (num < k) { // 如果数字数目小于要的数字
		arrangeRight(a, src, pr, k-num); // 对左边再移动k-num个 
	}
	return;
}

int main(int argc, char const *argv[])
{
	int size = sizeof(a) / sizeof(int);
	int k = 7;
	arrangeRight(a, 0, size-1, k);
	print(a, size-k,size-1);
	return 0;
}
