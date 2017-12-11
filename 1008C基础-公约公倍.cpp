#include "stdafx.h"
/*
1008: C基础-公约公倍
*/

#include<iostream>
using namespace std;
int GCD(int a, int b);
int LCM(int a, int b);
int main()
{
	int num1, num2, gcd, lcm;
	cin >> num1 >> num2;
	gcd = GCD(num1, num2);
	lcm = LCM(num1, num2);//输出最大公约数和最小公倍数
	cout << gcd << endl;
	cout << lcm << endl;
	return 0;
}
int GCD(int num1, int num2)
{
	if (num1%num2 == 0)
		return num2;
	return  GCD(num2, num1%num2);
}
int LCM(int a, int b)
{
	int temp_lcm;
	temp_lcm = a*b / GCD(a, b);//最小公倍数等于两数之积除以最大公约数
	return temp_lcm;
}