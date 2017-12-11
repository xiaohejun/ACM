#include <bits/stdc++.h>

using namespace std;

struct pep
{
	string name;
	float t;
	int has;
};


int main(){
	//freopen("in.txt", "r", stdin);
	int n;
	pep p;
	int num = 0;
	while(cin >> n) {
	    num = 0;
	    for (int i = 0; i < n; ++i)
	    {
	    	cin >> p.name >> p.t >> p.has;
	    	if(p.t >= 37.5 && p.has) {cout << p.name << endl; num++;}
	    }
	    cout << num << endl;
	}
	return 0;
}