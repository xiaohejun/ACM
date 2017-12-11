#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL INF = 1e9+7;
const int MAX_N = 1000+10;
int N;
LL a[MAX_N];
LL b;



int main(){
	//freopen("in.txt", "r", stdin);
	LL ans = 1L;
	while(cin >> N) {
	    ans = 1L;
	    for(int i = 0; i < N; i++) {
	    	scanf("%lld", &a[i]);
	    	scanf("%lld", &b);
	    	a[i] += b;
	    }
	    // (a*b*c)%d == (((a*b)%d)*c)%d。
	    for (int i = 0; i < N; ++i)
	    {
	    	ans *= a[i];
	    	ans %= INF;
	    }
	    printf("%lld\n", ans);
	}
	return 0;
}