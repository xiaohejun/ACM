//#include "stdafx.h"
/*
1093: 小鹏的镜子
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int max_n = 12;
const int max_len = 110;

char ch[max_n][max_len]; // 字符串
int result[max_n]; // 存结果

int solve(char * c, int len) {
	int result = len;
	int mid = (len-1) / 2;
	int front = 0, end = len-1;
	if (len == 1) return 1;
	while (c[front++] == c[end--])
	{
		if (front == mid+1 && end == mid) {
			result = mid+1;
			front = 0;
			mid = end / 2;
		}
	}
	return result;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) { // 输入数据，计算结果
		cin >> *(ch + i);
		result[i] = solve(*(ch + i), strlen(*(ch + i)));
	}
	for (int i = 0; i < t; i++) { // 输出结果
		cout << result[i] << endl;
	}
	//fclose(stdin);
	return 0;
}
