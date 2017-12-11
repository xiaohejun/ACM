#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10000+10;
bool is_prime[MAX_N];

void init(){
	memset(is_prime, true, sizeof is_prime);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAX_N; ++i)
	 {
	 	if (is_prime[i])
	 	{
	 		for(int j = 2*i; j <= MAX_N; j+=i) is_prime[j] = false;
	 	}
	 } 
}

int main(){
	freopen("in.txt", "r", stdin);
	int n;
	init();
	while(cin >> n) {
	    for (int i = 2; i <= n-2; ++i)
	    {
	    	if(is_prime[i] && is_prime[i+2]) printf("%d %d\n", i, i+2);
	    }
	}
	return 0;
}