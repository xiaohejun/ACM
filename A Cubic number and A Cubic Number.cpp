
#include "stdafx.h"
#include <iostream>  
#include <cmath>
using namespace std;

const int MAX_N = 10001;
const int MAX_T = 101;
int T; // 测试数量
bool ans = false;
long long p; // 素数
long long num[MAX_N]; // 立方数
long long diff[MAX_N];

bool contain(long long x);
void deal();
//bool isPrime(long long x);
void solve();
//bool openthree(long long x);

int main()
{
	freopen("in.txt", "r", stdin);
	cin >> T;
	deal(); // 预处理
	while (T--)
	{
		cin >> p;
		solve();
		cout << (ans ? "YES" : "NO") << endl;
	}
	fclose(stdin);
	return 0;
}


void solve() {
	if (contain(p)) {
		ans = true;
	}
}

// 小于7的直接不算了
bool contain(long long x) {
	if (x < 7) return false;
	int m = pow(x,1/3.0);
	long long tmp = num[m + 1] - num[m];
	bool flag = (tmp == x);
	cout << flag << endl;
	if (flag) return true;
	return false;
}


// 把立方数存起来
void deal() {
	for (int i = 1; i <= MAX_N; i++) {
		num[i] = i*i;
		num[i] *= i;
		//cout << num[i] << endl;
	}
}

/*
// 判断一个数是不是素数
bool isPrime(long long num)
{
	//两个较小数另外处理  
	if (num == 2 || num == 3)
		return 1;
	//不在6的倍数两侧的一定不是质数  
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//在6的倍数两侧的也可能不是质数  
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//排除所有，剩余的是质数  
	return 1;
}*/