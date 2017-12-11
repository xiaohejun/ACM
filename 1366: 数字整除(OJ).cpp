#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

/*
	1366: 数字整除
*/


int main()
{      
	freopen("in.txt", "r", stdin);
	char num[105];
	while(cin >> num){
		int len,n = 0,m; 
		if(num[0] == '0') break;
		len = strlen(num); // 得到字符串长度
		m = num[len-1] - '0'; // 得到个位数字
		for (int i = 0; i < len-1; ++i)
		{
			n = (n*10 + num[i] - '0')%17; // 模拟手算
		}
		m = m*5%17; 
		n -= m;
		if(n%17 == 0){
			cout << 1 << endl;
		} else cout << 0 << endl;
	}
	fclose(stdin);
	return 0;
}

