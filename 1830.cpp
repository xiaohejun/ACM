#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/*
	1830: Is Derek lying?(oj)

*/

const int max_n = 300010;
char ch[max_n];

int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	int N,X,Y;
	int dif;
	char c;
	cin >> T;
	while(T--) {
	    int ans = 0;
	    cin >> N >> X >> Y; // 问题数，X，Y
	    dif = abs(X-Y); // 不同的字符个数
	    for (int i = 0; i < N; ++i)
    	    {
    	    	cin >> ch[i];
    	    }
    	    for (int i = 0; i < N; ++i)
    	    {	
    	    	cin >> c;
    	    	if(ch[i] != c) ans++;
    	    }
    	    if(ans == dif) cout << "Not lying" << endl;
    	    else cout << "Lying" << endl;	    
	}
	//fclose(stdin);
	return 0;
}