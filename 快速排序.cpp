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

// 快速排序
void QuickSort(int *a, int s, int e) {
	if (s >= e) {
		return; // 边界条件
	}
	int key = a[s]; // 设置一个key是第一个数
	int i = s, j = e; // i和j指向起点和终点
	while (i != j)
	{
		while (i < j && a[j] >= key) j--; // j向前移动
		swap(a[i], a[j]); // 奇数次交换a[j] = key
		while (i < j && a[i] <= key) i++; // i向后移动
		swap(a[i], a[j]); // 偶数次关系交换a[i] = key
	}// 使得a[i] = key
	QuickSort(a, s, i-1); // 把key的左边进行快排
	QuickSort(a, i+1, e); // 把key的右边进行快排
}


int main(int argc, char const *argv[])
{
	int size = sizeof(a) / sizeof(int); // 计算数组的大小
	QuickSort(a, 0, size-1); // 从下标0到size-1进行快排
	for (int i = 0; i < size; i++) { // 打印输出
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}