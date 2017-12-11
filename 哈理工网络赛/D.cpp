#include <bits/stdc++.h>

using namespace std;


typedef long long LL;
int T;
int a,b;
int num[10] = {1,0,0,0,1,0,1,0,2,1};
int sum[10];

int getWei(int x){
	int res = 0;
	while(x) {
	    res ++;
	    x /= 10;
	}
	return res;
}

int main(){
	freopen("in.txt", "r", stdin);
	cin >> T;
	int aw,bw;
	LL ans;
	while(~scanf("%d%d", &a,&b)) {
	    // 判断[a,b]之内每个数字出现的次数
	    aw = getWei(a);
	    bw = getWei(b);


	}
	return 0;
}