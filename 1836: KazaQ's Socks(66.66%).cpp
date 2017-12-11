#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

/*
	1836: KazaQ's Socks(oj)

*/


int main()
{
	//freopen("in.txt", "r", stdin);
	long long n,k;
	int i = 0;
	while(cin >> n >> k && n && k) { // 输入n,k
		int ans = 1,tmp;
		if(k <= n) ans = k;
		else { // k>n的情况
			k -= n;
			tmp = k/(n-1); // 确定是奇数份还是偶数份
			if(k%(n-1) != 0) {ans = k%(n-1);}
			else {
				if(tmp%2 == 0) {
					ans = n;
				} else ans = n-1;
			}
		}
	    	cout << "Case #" << ++i << ": " << ans << endl;
	}
	//fclose(stdin);
	return 0;
}