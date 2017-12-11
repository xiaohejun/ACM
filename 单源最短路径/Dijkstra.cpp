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
int d[MAX_V]; // 到各结点的最短距离

void init(){ // 初始化
    fill(d, d+V, INF);
}

// 利用堆结构.复杂度O(|E|log|V|),当图中没有负数的权值时使用
void dijkstra(int s){
	priority_queue<P, vector<P>, greater<P> > que; // 从小到大排列优先按first的值
	d[s] = 0; // 开始点到到自己的距离是0
	que.push(P(0,s)); // 把第一个点入队
	while(!que.empty()){
        P p = que.top(); que.pop(); // 取得队头
        int v = p.second; // 得到结点
       // cout << char(v+97) << endl;
        if(d[v] < p.first) continue; // 不用更新了
        for(int i = 0; i < G[v].size(); i++){ // 开始每一条边进行更新
            edge e = G[v][i]; // 得到这一条边
            if(d[e.to] > d[v] + e.cost){ // 可以更新就放入队列
                d[e.to] = d[v] + e.cost; // 更新
                que.push(P(d[e.to], e.to));
            }
        }
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
	        G[from].push_back(edge(to, c));
	        //G[to].push_back(edge(from, c));
	    }
	    dijkstra(0);
	    for(int i = 0; i < V; i++){
	        cout << char(i+65) << "      " << d[i] << endl;
	    }
	}
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