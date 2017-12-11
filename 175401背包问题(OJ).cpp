#include "stdafx.h"
/*
1754: 01背包问题(OJ)
*/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int max_v = 1010; // 最大背包容量
const int max_n = 110; // 最大组数
int v[max_n]; // 每一个物品的体积
int w[max_n]; // 每一个物品的价值
int V, N; // 背包的容积，物品数量

int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> V >> N && V > 0 && N > 0)
	{	
		int F[max_v] = { 0 }; // 在前n个物品中选体积总和不超过v的最大价值
		for (int i = 1; i <= N; i++) { // 输入数据
			cin >> v[i] >> w[i]; // 输入体积和价值
		}
		// 处理数据
		for (int i = 1; i <= N; i++) { // 行,从上到下算
			for (int j = V; j >= 0; j--) { // 从右到左算
				if (j - v[i] >= 0) { // 判断防止j越界
					F[j] = max(F[j], F[j - v[i]] + w[i]); // 不选和选
				}
			}
		}
		cout << F[V] << endl; // 输出结果
	}
	//fclose(stdin);
	return 0;
}
