#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main() {
	// 正整数
	int n, k = 1, sum = 0;
	while (scanf("%d", &n) != EOF && n >= 1 && n <= 1e18)
	{
		while (k <= n)
		{
			if (pow(k, k) <= n)
			{
				sum++;
				k++;
			}
			else {
				break;
			}
		}
		printf("%d\n", sum);
		sum = 0;
		k = 1;
	}
	return 0;
}