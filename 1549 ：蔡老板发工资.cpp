#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

/*
	1549 ：蔡老板发工资
*/


int main()
{      

	//freopen("in.txt", "r", stdin);
	int n,ans,count;
	while(cin >> n && n){
		ans = 0;
		count = 0;
		int i = 0;
		while(++i){
			for(int j = 1; j <= i; j++){
				ans += i;
				count++;
				if(count == n) break;
			}
			if(count == n) break;
		}
		cout << ans << endl;
	}
	//fclose(stdin);
	return 0;
}

