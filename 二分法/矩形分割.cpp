#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MAX_R = 1000000+10;
const int MAX_N = 10000+10;

int R,N;
int area[MAX_R]; // 每一小列的面积.1表示0-1之间的面积

// 使得这些小矩形落在直线左边的面积必须大于等于落在右边的面积，且两边面积之差最小。并且，要使得大矩形在直线左边的的面积尽可能大。
bool C(int x){
	//cout << "mid = " << x << endl;
	LL left = 0L, right = 0L; // 左右两边的面积
	for(int i = 0; i <= x; i++){
		left += area[i];
	}
	for(int i = x+1; i <= R; i++){
		right += area[i];
	}
	//cout << left << "   " << right << endl;
	if(left > right) return true;
	else return false; 
}

void solve(){
	LL low = 0,high = R;
	while(low < high) {
	    LL mid = (low+high)/2;
	    if(C(mid)) high = mid-1; // 缩小值
	    else low = mid+1; // 扩大值
	}
	printf("%lld\n", high);
}


int main(){
	freopen("in.txt", "r", stdin);
	int L,T,W,H; // 左上角坐标(L,T),宽是W,高是H
	while(~scanf("%d%d", &R, &N)) {
	    memset(area, 0, sizeof area);
	    for (int i = 0; i < N; ++i)
	    {
	    	scanf("%d%d%d%d", &L, &T, &W, &H);
	    	for(int i = L+1; i <= L+W; i++){
	    		area[i] += H;
	    	}
	    }
	    solve();
	}
	return 0;
}