#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


/*
	求素数的个数，区间筛法  
*/

typedef long long ll;  
const int MAX_L = 100000000;  
const int MAX_SQRT_B = 1000000 + 10;  
  
bool is_prime[MAX_L];   // 装[a,b)之间的素数
bool is_prime_small[MAX_SQRT_B];  // 装[2,b^(1/2)中的素数
  
//对区间[a, b)内的整数执行筛选。is_prime[i - a] = true ==== i是素数  
void segment_sieve(ll a, ll b)  
{    
    // 初始化[0,sqrt(b))
    for (int i = 0; (ll)i * i < b; i++){  
        is_prime_small[i] = true;  
    }
    // 初始化  
    for (int i = 0; i < b - a; i++){  
        is_prime[i] = true;  
    }  
  
    for (int i = 2; (ll)i * i < b; i++){ // 从[2,sqrt(b))筛选  
        if (is_prime_small[i]){ // 如果这个数是素数
            for (int j = 2 * i; (ll)j * j < b; j += i)  
                is_prime_small[j] = false;  //筛[2,根号b)
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)  // 这个数在[a,b)中的倍数筛选
                is_prime[j - a] = false;   //筛[a, b)  
        }  
    }  
}  


int main()
{
	freopen("in.txt", "r", stdin);
	ll a,b;
	while(cin >> a >> b) { // 输入a,b
		int count = 0; // 计数器
		segment_sieve(a, b); // 从a,b区间筛选
		for (int i = 0; i < b - a; i++){  
			if (is_prime[i]) count++; // 计数
		}  
		cout << count << endl; // 输出结果
	}
	fclose(stdin);
	return 0;
}