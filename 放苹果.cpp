/**
* M个同样的苹果放在N个盘子。允许有盘子空着不放
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int f(int m, int n) {
	// 如果盘子比苹果多，那么多的盘子相当于不要，空着
	if (n > m)
	{
		return f(m, m);
	}
	if (m == 0)
	{
		return 1; // 没有苹果，九一种放法
	}
	if (n == 0)
	{
		return 0; // 没有盘子，没有放法
	}
	// m个苹果，n个盘子 n<=m
	return f(m, n - 1) + f(m - n, n); // 有盘子空着(至少空一个)+没有盘子空着的方法
}


int main(int argc, char const *argv[])
{
	int t, m, n;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
	return 0;
}