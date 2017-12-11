#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 100+10;
int m,n;
int value[MAX_M][MAX_M];
string str;


void solve(){
	int len = str.length();
	// 对字符串进行简化.减少不必要的操作
	// 可以去掉的操作: AB  BA  CC DD AAAA   BBBB CDDC DCDC    
	// 可以简化的操作: 3A = B  3B = A 
	for (char i = 0; i < count; ++i)
	{
		/* code */
	}
}

int main(){
	while(~scanf("%d%d", &m, &n)) {
	    for(int i = 0; i < m; i++)
	    	for(int j = 0; j < n; j++)
	 		scanf("%d", &value[i][j]);  
	    cin >> str;
	    solve(); 	
	}
	return 0;
}