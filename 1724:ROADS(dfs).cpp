#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>



using namespace std;

/*
	1724:ROADS(dfs)

*/

int K,N,R; // 钱，要到达的城市，道路数目
struct Road // 路的信息
{
	int d,L,t; // 终点，长度，过路费
};

vector<vector<Road>> G(110); // 邻接表
int minLen; // 走的最小长度
int totalLen; // 在走的路走的长度
int totalCost; // 走路花的钱
bool visited[110]; // 这个城市是否走过
int minL[110][10010];

// 从s开始走
void dfs(int s){
	if (s == N) // 走到终点了
	{
		minLen = min(minLen,totalLen); // 更新minLen的操作
		return;
	}
	for (int i = 0; i < G[s].size(); ++i) // 走每一条路
	{
		Road r = G[s][i];
		if(totalCost + r.t > K) continue; // 钱不够，不能走
		if(!visited[r.d]) { // 没有走过
			if(totalLen+r.L >= minLen) continue; // 剪枝
			if(totalLen+r.L >= minL[r.d][totalCost+r.t]) continue; // 剪枝
			minL[r.d][totalCost+r.t] = totalLen + r.L; // 更新
			totalLen += r.L; // 路程增加
			totalCost += r.t; // 花费增加
			visited[r.d] = true; // 访问过
			dfs(r.d); // 开始下一个点走
			visited[r.d] = false; // 另一种走法
			totalLen -= r.L; // 路程增加
			totalCost -= r.t; // 花费增加
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> K >> N >> R;
	for (int i = 0; i < R; ++i)
	{	
		int s;
		Road r;
		cin >> s >> r.d >> r.L >> r.t;
		if(s != r.d) G[s].push_back(r); // 放入数据
	}
	memset(visited, false, sizeof(visited)); // 初始化成都没有访问过
	for (int i = 0; i < 110; ++i) // min[i][j]表示走到城市i花费j块钱时的总长度
	{
		for (int j = 0; j < 10010; ++j)
		{
			minL[i][j] = (1 << 30);
		}
	}
	minLen = 1 << 30; // 初始化最优路径的长度为一个大的值
	totalCost = 0; // 总花费为0
	visited[1] = true; // 起点标记成访问过
	dfs(1); // 从起点开始深度优先搜索
	if (minLen < (1 << 30)) // 输出结果
	{
		cout << minLen << endl;
	} else cout << "-1" << endl;
	//fclose(stdin);
	return 0;
}