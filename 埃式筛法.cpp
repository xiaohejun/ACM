#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


/*
	求素数的个数，埃式筛法  O(nloglogn	)
*/

const int max_n = 1000010;
int prime[max_n]; // 第i个素数
bool is_prime[max_n]; // 这个数是不是素数

// 计算n之前的素数
int sieve(int n){
	int p = 0;
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false; // 0和1不是素数
	for (int i = 2; i <= n; ++i)
	{
		if (is_prime[i]) // 如果是素数
		{
			prime[p++] = i; // 存起来
			for(int j = i; j <= n; j+=i) is_prime[j] = false; // 这个数的倍数都不是素数
		}
	}
	return p;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	while(cin >> n) {
	    cout << sieve(n) << endl;
	}
	fclose(stdin);
	return 0;
}