#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int n;

int main(){
	//freopen("in.txt", "r", stdin);
	// 立方和的公式(n(n+1)/2)^2
	/*
		模运算与基本四则运算有些相似，但是除法例外。其规则如下：
		(a + b) % p = (a % p + b % p) % p 
		(a - b) % p = (a % p - b % p) % p 
		(a * b) % p = (a % p * b % p) % p 
		a ^ b % p = ((a % p)^b) % p 
		结合律：
		((a+b) % p + c) % p = (a + (b+c) % p) % p 
		((a*b) % p * c)% p = (a * (b*c) % p) % p 
		交换律：
		(a + b) % p = (b+a) % p 
		(a * b) % p = (b * a) % p 
		分配律：
		(a+b) % p = ( a % p + b % p ) % p 
		((a +b)% p * c) % p = ((a * c) % p + (b * c) % p) % p 

	*/
	LL ans = 1L,res;
	while(cin >> n) {
	    ans = 1L;
	    res = (((n%10000)*((n+1)%10000))%10000/(2L%10000)) % 10000;
	    res = ((res%10000)*(res%10000))%10000;
	    printf("%04lld\n", res);
	}
	return 0;
}