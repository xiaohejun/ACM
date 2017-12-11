#include "stdafx.h"
/*
002:马走日
*/

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;


int T; // 测试数据
int n, m; // 棋盘行列数
int x, y; // 初始位置
int dx[8] = { 2,-2,2,-2,1,-1,-1,1 }; // 八个方向移动
int dy[8] = { 1,-1,-1,1,2,-2,2,-2 };
int map[15][15] = { 0 }; // 棋盘初始值0，代表没有访问过
typedef pair<int, int> P;
queue<P> que;

bool isAns() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int i;
	cin >> T;
	while (T--)
	{
		int ans = 0; // 结果
		cin >> n >> m >> x >> y;
		memset(map, 0, sizeof(map)); // 初始化
		map[x][y] = 1; // 起点被访问过
		que.push(pair<int, int>(x, y)); // 把起点的位置压入队列
		// 开始计算
		while (que.size())
		{
			// 从队列的最前端取出元素
			P p = que.front(); que.pop();
			if (isAns()) ans++;
			// 如果取出的状态已经是终点，退出
			for (i = 0; i < 8; i++) { // 走八个方向
				// 移动后的方向
				int nx = p.first + dx[i], ny = p.second + dy[i];
				// 判断是不是可以移动
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0) { 
					map[nx][ny] = 1; // 走到这个点
					que.push(P(nx,ny)); // 压入
				}
			}
			//if (isAns()) ans++;
		}
		cout << ans << endl;
	}
	fclose(stdin);
	return 0;
}
