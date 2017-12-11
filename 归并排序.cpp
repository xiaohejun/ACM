#include "stdafx.h"
#include <iostream>
using namespace std;

int a[] = { 4,8,9,10,6,7,1,3,2,5 };
int tmp[10];

// 归并
void Merge(int *a, int s, int m, int e, int *tmp) {
	int left = s, right = m+1, p = 0; // 两个下标指向两半的起点
	while (left <= m && right <= e)
	{
		tmp[p++] = a[right] < a[left] ? a[right++] : a[left++];
	}
	while (left <= m)
	{
		tmp[p++] = a[left++];
	}
	while (right <= e)
	{
		tmp[p++] = a[right++];
	}
	for (p = 0; p < e - s + 1; p++) {
		a[s + p] = tmp[p];
	}
}


// 归并排序
void MergeSort(int *a, int s, int e, int *tmp) {
	if (s < e) { // s < e才能操作
		int m = s + (e - s) / 2; // 把数组分成两半
		MergeSort(a, s, m, tmp); // 排序前一半
		MergeSort(a, m+1, e, tmp); // 排序后一半
		Merge(a, s, m, e, tmp); // 进行归并
	}
}

int main(int argc, char const *argv[])
{
	int size = sizeof(a) / sizeof(int); // 计算数组的大小
	MergeSort(a, 0, size-1, tmp); // 归并排序
	for (int i = 0; i < size; i++) { // 打印输出
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}