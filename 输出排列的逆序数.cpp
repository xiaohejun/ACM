/**
* 求排列的逆序数
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int a[100000];
int tmp[100000];

void Merge(int *a, int s, int m,int e, int *tmp) {
	int p = 0;
	int i = s, j = m+1;
	while (i <= m && j <= e)
	{
		tmp[p++] = a[i] > a[j] ? a[i++] : a[j++];
	}
	while (i <= m)
	{
		tmp[p++] = a[i++];
	}
	while (j <= e)
	{
		tmp[p++] = a[j++];
	}
	for (int i = 0; i < e - s + 1; i++) {
		a[s + i] = tmp[i];
	}
}

void MergeSort(int *a, int s, int e, int *tmp) {
	if (s < e) {
		int m = s + (e - s) / 2;
		MergeSort(a, s, m, tmp); // 数组前半部分进行归并排序
		MergeSort(a, m+1, e, tmp); // 后半部分进行归并排序
		Merge(a, s, m, e, tmp); // 归并
	}
}



long long MergeSortAndCount(int *a, int s, int e) {
	long long count = 0;
	if (s >= e) {
		return (long long)0;
	}
	// 1.将数组分成两半，分别求两边的逆序数
	int m = s + (e-s)/2;
	count += MergeSortAndCount(a, s, m); // 前半部分进行计算逆序数的个数
	count += MergeSortAndCount(a, m+1, e); // 后半部分进行计算逆序数的个数
	// 2.左右两边排序后左半边取一个数，右半边取一个数
	MergeSort(a, s, m, tmp); // 前半部分进行归并排序
	MergeSort(a, m+1, e, tmp); // 后半部分进行归并排序
	int i = s, j = m + 1;
	while (i <= m && j <= e)
	{	
		if (a[i] > a[j] && j <= e) {
			count += (long long)(e - j + 1);
			i++;
		}
		else {
			j++;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{	
	int n,i;
	while (cin >> n && n <= 100000) {
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << MergeSortAndCount(a, 0, n-1) << endl;
	}
	return 0;
}
