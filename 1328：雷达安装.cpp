#include "stdafx.h"
/*
1328：雷达安装
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// 小岛的相关信息
typedef struct Land {
	double left; // 和x轴相交的左边端点
	double right; // 和x轴相交的右边端点
	int x; // 横坐标
	int y; // 纵坐标
}Land;

const int MAX_N = 1010;
int n, d;
Land land[MAX_N]; // 小岛

int minimalNum();
bool cmp(Land a, Land b);

int main()
{
	//freopen("in.txt", "r", stdin);
	int test = 0;
	while (cin >> n >> d && (n || d)) // 输入相关数据
	{
		for (int i = 0; i < n; i++) {
			cin >> land[i].x >> land[i].y; // 输入岛的坐标
		}
		cout << "Case " << ++test << ": " << minimalNum() << endl;
	}
//	fclose(stdin);
	return 0;
}

// 比较函数
bool cmp(Land a, Land b) {
	if (a.right < b.right) {
		return true;
	}
	else if(a.right == b.right){
		if (a.left > b.left) return true;
	}
	return false;
}

int minimalNum() {
	int minNum = 0; // 安装雷达的最少数量
	int i; // 循环变量
	// 计算以小岛为圆心做圆和x轴的交点
	for (i = 0; i < n; i++) {
		if (land[i].y > d) return -1; // 和x轴没有交点
		land[i].left = land[i].x - sqrt(d*d - land[i].y*land[i].y); // 计算左边
		land[i].right = land[i].x + sqrt(d*d - land[i].y*land[i].y); // 计算右边
	}
	// 根据右边端点从小到大排序，如果右边端点相同，根据左边端点大到小排序
	sort(land, land+n, cmp);
	Land l = land[0]; // 第一个岛标记
	minNum++;
	// 标记一个点的右边，直到下一个点的左边大于这个点，那就要更新点的标记
	for (i = 1; i < n; i++) {
		if (l.right < land[i].left) {
			l = land[i]; // 更新点
			minNum++;
		}
	}
	return minNum;
}

