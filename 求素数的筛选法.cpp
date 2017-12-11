#include "stdafx.h"
/*
	求素数的高效算法
*/


#include <iostream>
#include <cmath>
using namespace std;

// 筛选法
bool isPrime(int num) {
	// 两个小的数
	if ( num == 2 || num == 3) return true;
	// 不在6的倍数的两侧一定不是素数
	if ( num%6 != 1 && num%6 != 5) return false;
	int tmp = sqrt(num);
	for (int i = 5; i <= tmp; i+=6) {
		if (num%i == 0 || num%(i+2) == 0) return false;
	}
	return true;
}

int n;

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> n;
	cout << (isPrime(n) ? "Y" : "N") << endl;
	//fclose(stdin);
	return 0;
}


