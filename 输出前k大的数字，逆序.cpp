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

// 快速排序
void QuickSort(int *a, int s, int e) {
	if (s >= e) {
		return; // 边界条件
	}
	int key = a[s]; // 设置一个key是第一个数
	int i = s, j = e; // i和j指向起点和终点
	while (i != j)
	{
		while (i < j && a[j] <= key) j--; // j向前移动
		swap(a[i], a[j]); // 奇数次交换a[j] = key
		while (i < j && a[i] >= key) i++; // i向后移动
		swap(a[i], a[j]); // 偶数次关系交换a[i] = key
	}// 使得a[i] = key
	QuickSort(a, s, i - 1); // 把key的左边进行快排
	QuickSort(a, i + 1, e); // 把key的右边进行快排
}

int main(int argc, char const *argv[])
{	
	int n,i,k;
	while (cin >> n && n < 100000) {
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> k;
		arrangeRight(a, 0, n-1, k); // 把第k大的数移动到右边
		QuickSort(a, n-k, n-1); // 进行快速排序
		print(a, n - k, n-1); // 打印
	}
	return 0;
}
