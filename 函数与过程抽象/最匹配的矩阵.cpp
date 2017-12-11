#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 100+10;
const int MAX_N = 100+10;
int A[MAX_M][MAX_N];
int B[MAX_M][MAX_N];
int m,n,r,s;


void solve(){
	int sum = 0;
	int min = 1 << 30;
	int x = 1,y = 1; // 记录最小子矩阵的左上角位置
	// m:3 n:3
	// r:2 s:2
	for (int i = 1; i <= m-r+1; ++i) // 行控制
	{	
		for(int j = 1; j <= n-s+1; j++){ // 列控制
			sum = 0;
			for(int k = i, kk = 1; k < i+r; k++, kk++){
				for(int l = j, ll = 1; l < j+s; l++, ll++){
					sum += abs(A[k][l]-B[kk][ll]);
				}
			}
			if(sum < min) {x = i; y = j; min = sum;}
		}
	}
	// 输出结果
	for(int i = x, ii = 1; ii <= r; i++, ii++){
		for(int j = y, jj = 1; jj <= s; j++, jj++){
			printf("%d ", A[i][j]);
			//if(++jj == s) printf(" ");
		}
		printf("\n");
	}
}

int main(){
	//freopen("in.txt", "r", stdin);
	while(cin >> m >> n) {
	    for(int i = 1; i <= m; i++)
	    	for(int j = 1; j <= n; j++)
	    		cin >> A[i][j];
	    cin >> r >> s;
	    for(int i = 1; i <= r; i++)
	    	for(int j = 1; j <= s; j++)
	    		cin >> B[i][j];
	    solve();
	}
	return 0;
}