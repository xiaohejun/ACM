#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

/*
	1499: 橙子姐姐的围棋
*/


int main()
{      

	//freopen("in.txt", "r", stdin);
	int t,m,n;
	cin >> t;
	while(t--){
		cin >> m >> n; // 输入m和n
		int min = m < n ? m : n;
		long long count = 0;
		for (int i = 1; i <= min; ++i)
		{
			count += ((m-i)*(n-i));
		}
		cout << count << endl;
	}
	//fclose(stdin);
	return 0;
}

