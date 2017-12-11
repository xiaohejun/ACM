#include "stdafx.h"
/*
1287: 防御导弹
分析：类似于求最长下降子序列
子问题：以每一个数作为终点形成的最长下降序列的长度
maxLen[k] = { if high[k]<=high[j]: maxLen[k] = max(maxLen[k],maxLen[j]+1) 1<=j<k} 2<=k<=count
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 25;
int high[max_n];
int maxLen[max_n];

int main()
{
	//freopen("in.txt", "r", stdin);
//	memset(high, -1, sizeof(high)); // 初始化
	int i = 1;
	int count = 0;
	while (cin >> high[i++]) { maxLen[i - 1] = 1; };
	count = i - 2; // 记录总个数
	// 计算
	for (int k = 2; k <= count; k++) {
		for (int j = 1; j < k; j++) {
			if (high[k] <= high[j]) {
				maxLen[k] = max(maxLen[k],maxLen[j]+1);
			}
		}
	}
	cout << *max_element(maxLen + 1, maxLen+count+1) << endl;
	//fclose(stdin);
	return 0;
}
