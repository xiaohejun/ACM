#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int T,k;
string s;
int cases = 0;

void solve(){
	LL maxNum = 0L;
	LL ans = 0L;
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{	
		if(s[i] == '0' || i+k > len) continue;
		ans = 0L;
		for (int j = i; j < i+k; ++j)
		{
			ans += s[j]-'0';
			ans *= 2;
		}
		ans /= 2L;
		maxNum = max(ans, maxNum);
	}
	printf("Case #%d: %lld\n", ++cases, maxNum);
}

int main(){
	//freopen("in.txt", "r", stdin);
	cin >> T;
	while(T--) {
	    cin >> k >> s;
	    solve();
	}
	return 0;
}