#include "stdafx.h"
/*
1088:滑雪(POJ)
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Loca{
	int value; // 值
	int x; // 横坐标
	int y; // 纵坐标
}Loca;

const int max_r = 110;
Loca loca[max_r*max_r];
Loca tmp[max_r*max_r];
int L[max_r][max_r]; // 从这个点出发的最长滑行长度
int nx[4] = {-1,1,0,0}; // 上下左右，四个方向
int ny[4] = {0,0,-1,1};
int R, C; // 输入数据的行和列
int maxL = 1;

bool cmp(Loca a, Loca b) {
	return a.value < b.value;
}

// 得到坐标是x,y的值
int getValue(int i, int j) {
	return tmp[i*C+j].value;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> R >> C; // 输入行，列数
	int k = 0;
	int dx = 0, dy = 0;
	for (int i = 0; i < R; i++) { // 输入数据
		for (int j = 0; j < C; j++) {
			cin >> loca[k].value; // 输入值
			loca[k].x = i; // 横坐标
			loca[k].y = j; // 纵坐标
			tmp[k].value = loca[k].value; // 输入值
			tmp[k].x = i; // 横坐标
			tmp[k].y = j; // 纵坐标
			L[i][j] = 1;
			k++;
		}
	}
	sort(loca, loca +k, cmp);
	for (int n = 0; n < k; n++) { // 从小到大开始找
		//cout << "n=" << n << "   " << loca[n].value << endl;
		for (int i = 0; i < 4; i++) { // 上下左右
			dx = loca[n].x + nx[i]; dy = loca[n].y + ny[i];
			if (dx >=0 && dx < R && dy >= 0 && dy < C && getValue(dx,dy) < loca[n].value) {
				L[loca[n].x][loca[n].y] = max(L[loca[n].x][loca[n].y], L[dx][dy]+1); // 求出值
			}
		}
		//cout << L[loca[n].x][loca[n].y] << endl;
		maxL = max(maxL, L[loca[n].x][loca[n].y]);
	}
	cout << maxL << endl;
	//fclose(stdin);
	return 0;
}
