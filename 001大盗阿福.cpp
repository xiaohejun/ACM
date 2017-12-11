#include "stdafx.h"
/*
001:大盗阿福
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 100010;
int T; // T组数据
int N; // 店铺数量
int money[max_n]; // 钱的数量
int ans[max_n];

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++) { // 输入数据
			cin >> money[i];
		}
		ans[0] = 0; ans[1] = money[1];
		for (int i = 2; i <= N; i++) {
			ans[i] = max(ans[i-2]+money[i], ans[i-1]);
		}
		cout << ans[N] << endl;
	}
	//fclose(stdin);
	return 0;
}
