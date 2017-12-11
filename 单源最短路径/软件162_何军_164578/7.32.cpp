/*************************************************************************
    > File Name: 7.32.cpp
    > Author: 何军 
    > Sub: Prime算法求最小生成树
    > Created Time: 2017年11月20日 星期一 22时50分31秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;


struct edge // 边的结构体
{
	int to,cost; // 终点,权值
	edge(int t, int c):to(t),cost(c){}
};

typedef pair<int, int> P; // first是最短距离,second是顶点的编号

const int MAX_V = 1000+10; // 结点数的最多情况
const int INF = 1 << 30; // 权值最大值
int V,E; // 结点数,边数
vector<edge> G[MAX_V]; // 邻接表表示图
int mincost[MAX_V]; // 从结合x出发的边到每个结点的权值最小值
bool used[MAX_V]; // 结点是否被用过

void init(){ // 初始化
    memset(used, false, sizeof used);
    fill(mincost, mincost+V, INF); // 最小距离都设置成最大值
}

// 使用优先队列维护mincost[]的值,使得复杂度是O(|E|log|v|)
void prim(){
	init(); // 初始化
	priority_queue<P, vector<P>, greater<P> > que; // 从小到大排列优先按first的值
	mincost[0] = 0; // 开始从结点0开始
	que.push(P(0,0)); // 把第一个点入队
	while(!que.empty()){
	        P p = que.top(); que.pop(); // 取得队头 
	        int v = p.second; // 得到结点
	        // a c b d h g f e 
	        if(used[v]) continue; // 结点访问过就跳过
	        cout << char(v+97) << " "; // 打印结点顺序
	        for(int i = 0; i < G[v].size(); i++){ // 开始每一条边进行更新
	            edge e = G[v][i]; // 得到这一条边
	            mincost[e.to] = min(mincost[e.to], e.cost); // 更新值
	            if(!used[e.to]) que.push(P(mincost[e.to], e.to)); // 如果结点没有访问过.加入队列
	        }
	        used[v] = true; // 这个结点访问过
	}
}


int main(){
	freopen("Prim.txt", "r", stdin);
	while(cin >> V >> E && V && E){
	    for(int i = 0; i < E; i++){
	        int from,to,c;
	        scanf("%d%d%d", &from, &to, &c);
	        G[from].push_back(edge(to, c));
	        G[to].push_back(edge(from, c)); // 无向图
	    }
	    prim();
	}
	return 0;
}


/*
8 14
0 1 4
0 2 3
1 2 5
1 3 5
1 4 9
2 3 5
2 7 5
3 4 7
3 5 6
3 6 5
3 7 4
4 5 3
5 6 2
6 7 6
*/

/*
a c b d h g f e
*/

