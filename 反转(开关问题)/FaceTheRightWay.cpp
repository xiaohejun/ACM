#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5000+10;
int N;
int dir[MAX_N]; 

// B:面向后方,F:面向前方. B:1  F:0  全部变成F需要的最少操作次数M和对应的K
void solve(){
		
}


int main(int argc, char const *argv[])
{
	freopen("FaceTheRightWay.txt", "r", stdin);
	char c;
	while(cin >> N && N) {
	    for (int i = 0; i < N; ++i)
	    {	
	    	cin >> c;
	    	dir[i] = (c=='B') ? 1 : 0;
	    }
	    solve();
	}
	return 0;
}