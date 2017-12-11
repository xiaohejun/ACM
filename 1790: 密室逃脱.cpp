#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
	1790: 密室逃脱
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, ans, flag;
	bool is;
	while(cin >> n && n != 0){
		ans = 0; is = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> flag;
			if(flag == 0) {is = false;}
			if(flag%2 == 0 && flag != 0 && is) ans += flag;
		}
		cout << ans << endl;
	}
	//fclose(stdin);
	return 0;
}



