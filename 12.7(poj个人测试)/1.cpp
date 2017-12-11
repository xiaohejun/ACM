#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;



char arr[10][10];
const int M = 8;
const int N = 8; 
char c;
vector<P> p[2];

/*
  12345678
A O.......
B O......X
C O.....XX
D O....XXX
E .O...XXX
F ........
G ..O..XXX
H ........
A1-A2
A1-C3
A1-E1
B1-A2
B1-B3
B1-D3
B1-F1
C1-B2
C1-C4
C1-D2
C1-G1
D1-C2
D1-D5
D1-F3
D1-H1
E2-D2
E2-D3
E2-E6
E2-F1
E2-F2
E2-G4
G3-F2
G3-F3
G3-H3
G3-H4
*/


void solve(){
	int flag = (c == 'O' ? 0 : 1);
	for (int i = 0; i < p[flag].size(); ++i)
	{   	
		/*
1.可以将棋子沿着直线移动，可以是左，右，上，下或对角线。

2.棋子可以移动的空间数由棋子移动的行，列或对角线上的棋子总数确定。件只能移动这个确切的数字，不能更多，不能少。

3.玩家可以跳过自己的棋子。 

4.玩家不得跳过对手的棋子。

5.玩家可以通过登陆来捕捉对手的棋子。

6.玩家不得在已经占据的空间上登陆。
		*/
		P tmp = p[flag][i];
		if(){ // 上

		}
	}
}

int main(){
	freopen("1.txt", "r", stdin);
	while(true) {
	    	for (int i = 1; i <= 8; ++i)
		{
			for (int j = 1; j <= 8; ++j)
			{	
				cin >> arr[i][j];
				if(arr[i][j] == 'O') p[0].push_back(P(i,j));
				else if(arr[i][j] == 'X') p[1].push_back(P(i,j));
			}
		}
		if(cin >> c) {
			solve();
			p[0].clear(); p[1].clear();
		}
		else break;
	}
	return 0;
}