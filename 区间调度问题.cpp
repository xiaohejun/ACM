/*
	区间调度问题：贪心算法，找一个最好的情况
*/
#include "stdafx.h"
#include <iostream>  
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
int s[MAX_N]; // 时间开始
int t[MAX_N]; // 结束时间
pair<int, int> v[MAX_N]; // second开始时间和 first结束时间
int N;

int main()
{	
	freopen("in.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		v[i].second = s[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> t[i];
		v[i].first = t[i];
	}
	sort(v, v+N); // 根据first排序，结束时间
	int t = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		if (t < v[i].second) { // 前一个的结束时间小于后一个的开始时间
			t = v[i].first;
			ans++;
		}
	}
	cout << ans << endl;
	fclose(stdin);
	return 0;
}
