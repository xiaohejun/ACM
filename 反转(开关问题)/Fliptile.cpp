#include <iostream>
#include <cstdio>N) in one lin

using namespace std;

const int MAX = 20;
int M,N;
int a[MAX][MAX];

int getBit(int n, int i){
	return (n >> i)&1;
}



void solve(){
	cout << (15*15*(1 << 15)) << endl;
}


int main(int argc, char const *argv[])
{
	freopen("Fliptile.txt", "r", stdin);
	while(cin >> M >> N && M && N) {
		for (int i = 1; i <= M; ++i) // 0是白,1是黑,全部变成0
		{
			for (int j = 1; j <= N; ++j)
			{
				cin >> a[i][j];
			}
		}
		solve();
	}
	return 0;
}