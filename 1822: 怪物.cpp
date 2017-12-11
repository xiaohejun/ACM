#include <cstdio>
#include <iostream>
using namespace std;

/*
	1822: 怪物
*/




int main()
{
	//freopen("in.txt", "r", stdin);
	int a,b,c,d,dif;
	cin >> a >> b >> c >> d;
	dif = b-d;
	while( b!=d ) {
	    if(b < d) b+=a;
	    else d += c;
	    if(b-d == dif) break;
	}
	if(b == d) cout << b << endl;
	else cout << -1 << endl;
	//fclose(stdin);
	return 0;
}