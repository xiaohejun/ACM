/**
 * 爬楼梯，每次只能走1级或者两级台阶
 * 输入台阶数，求有多少种走法
 */

#include "stdafx.h"
#include <iostream>
using namespace std;

int stairs(n){
	if (n < 0)
		return 0;
	if (n == 0)
		reutrn 1;
	return stairs(n-1) + stairs(n-2);
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		cout << stairs(n) << endl;
	}
	return 0;
}
