/**************************

当图中不存在权值是负数的情况可以用该算法

***************************/

#include <bits/stdc++.h>

using namespace std;

//---------------------普通方法.复杂度O(|V|^2)------------
const int INF = 1 << 30;
const int MAX_V = 1000+10; // 结点数的最多个数
const int MAX_E = 1000+10; // 边数的最多个数
int cost[MAX_V][MAX_V]; // 边u,v之间的权值
int d[MAX_V]; // 顶点s出发的最短距离
bool used[MAX_V]; // 已经使用过的顶点
int V,E; // 顶点数,边的数


void init(){
    fill(d, d+V, INF);
    fill(used, used+V, false);
    for (int i = 0; i < V; ++i)
    {
	for (int j = 0; j < V; ++j)
	{
		cost[i][j] = INF;
	}
    }
}

// 操作过程和Prim算法有几分相似
void dijkstra_base(int s){
	d[s] = 0;

	while(true) {
	    int v = -1;
	    for (int u = 0; u < V; ++u)
	    {
	    	if(!used[u] && (v == -1 || d[u] < d[v])) v = u; // 找距离最小的结点
	    }

	    if(v == -1) break; // 如果是-1
	    cout << (char)(v+65) << endl;
	    used[v] = true; // 标志为已经访问过
	    for(int u = 0; u < V; u++){
	    	d[u] = min(d[u], d[v]+cost[v][u]); // 更新值
	    }
	    for(int u = 0; u < V; u++){
	    	cout << d[u] << " ";
	    }
	    cout << endl;
	}
}



int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    while(cin >> V >> E && V && E){
        init(); // 一开始先初始化数据
        for(int i = 0; i < E; i++){
            int from,to,c;
            scanf("%d%d%d", &from, &to, &c);
            cost[from][to] = cost[to][from] = c; // 无向图
        }
        dijkstra_base(0);
        for(int i = 0; i < V; i++){
            cout << char(i+65) << "      " << d[i] << endl;
        }
    }
    fclose(stdin);
	return 0;
}

/*
A      0
B      2
C      5
D      7
E      11
F      8
G      16
*/

/*

*/
