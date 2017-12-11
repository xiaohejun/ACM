/*************************************************************************
    > File Name: Prime.cpp
    > Author: 何军 
    > Sub: Prime算法球最小生成树
    > Created Time: 2017年11月20日 星期一 22时50分31秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100; // 最多的结点个数
const int INF = 1 << 30; // 权值无穷大的值
int cost[MAX_V][MAX_V]; // cost[u][v]表示边e=(u,v)的权值(不存在的情况设置成INF)
int mincost[MAX_V]; // 从结合x出发的边到每个结点的权值最小值
bool used[MAX_V]; // 结点i是否在集合x中(x集合是已经选择了的结点)
int V,E; // 顶点数,边数

// prim算法求最小生成树的权值的和
int prim(){
	for(int i = 0; i < V; i++){
		mincost[i] = INF; // 初始化到每个结点的最小权值是最大的
		used[i] = false; // 都没有加入选择了的结点集合中
	}
	mincost[0] = 0; // 从第一个结点开始出发找最小生成树.自己到自己的最小权值设置成0
	int res = 0; // 最小生成树的权值之和
	while(true) { // 直到所有结点都加入集合x中退出循环
	    int v = -1; // 图结点标号是从0开始的,所以如果没有找到点便可以作为退出条件
	    // 从不属于x集合的结点中找从x到最小权值的点
	    for(int u = 0; u < V; u++){
	    	if(!used[u] && (v==-1 || mincost[u] < mincost[v])) v = u;
	    }
	    if(v == -1) break; // 没有找到符合的点
	    used[v] = true; // 把结点加入到集合x
	    cout << (char)(v+97) << " "; // 输出加入集合的顺序
	    res += mincost[v]; // 把选择的边加到结果中
	    //cout << "res=" << mincost[v]  << " ";
	    for(int u = 0; u < V; u++){
	    	mincost[u] = min(mincost[u], cost[v][u]); // 更新到各结点的最小值
	    }
	}
	cout << endl;
	return res; // 返回结果
}

void init(){
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			cost[i][j] = INF;
		}
	}
}

int main(){
	freopen("Prim.txt", "r", stdin);
	while(~scanf("%d%d", &V,&E)) { // 输入结点数
	    cout << "V=" << V << " E=" << E << endl;
	    int u,v;
	    init();
	    for (int i = 0; i < E; ++i)
	    {	
	    	scanf("%d%d", &u,&v);
	    	scanf("%d", &cost[u][v]);
	    	cost[v][u] = cost[u][v]; // 无向图
	    }

	    printf("%d\n", prim());
	}
	fclose(stdin);
	return 0;
}


