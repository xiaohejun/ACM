#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;
long long a[20];
void deal()
{
	for (int i = 1; i <= 15; i++) // 计算k的k次方
	{
	long long result = 1;
	for (int j = 1; j <= i; j++)
	{
		result *= i;
	}
		a[i] = result;
	}
	a[16] = (long long)1e18 * 9; // 界限是1e18
}
int main()
{
	deal();
	long long n;
	int sum = 0;
	while (cin >> n)
	{
		for (int i = 1; i <= 16; i++)
		{
			if (a[i] <= n)
			{
				sum++;
			} else break;
		}
		cout << sum <<endl;
		sum = 0;
	}
}
