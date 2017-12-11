/*****************************

复杂度:O(|V|*|E|)

*****************************/


#include  <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;
const int MAX_V = 1000+10; // 结点最多的个数
const int MAX_E = 1000+10; // 边的最多个数

struct edge { int from, to, cost; }; // 边的结构
edge es[MAX_E]; // 边
int d[MAX_V]; // 到点的最短距离
int V,E; // 点数和边数


// d[to] = min{d[from]+(从from到to的距离) | e(from,to)}
void bellmanFord(int s){ // 从点s到其他点的最短距离
    for(int i = 0; i < V; i++) d[i] = INF; // 把每一个点的距离初始化
    d[s] = 0; // 起点距离是0
    while(true){
        bool update = false;
        for(int i = 0; i < E; i++){ // 如果是无向图的话就是边的两倍
            edge e = es[i]; // 取出每一条边
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){ // 更新到点的距离
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break; // 直到没有更新为止
    }
}


bool find_negative_loop(){ // 判断有没有负圈
    memset(d, 0, sizeof d);
    for(int i = 0; i < V; i++){
        for (int j = 0; j < E; ++j)
        {   
            edge e = es[j];
            if(d[e.to] > d[e.from]+e.cost){
                d[e.to] = d[e.from] + e.cost;
                if(i == V-1) return true; // 更新了V次.说明有负圈
            }
        }
    }
    return false;
}

int main(){
    freopen("in.txt", "r", stdin);
    while(cin >> V >> E && V && E){
        for(int i = 0; i < E; i++){
            int from,to,cost;
            scanf("%d%d%d", &from, &to, &cost);
            es[i].from = from; es[i].to = to; es[i].cost = cost;
            es[E+i].to = from; es[E+i].from = to; es[E+i].cost = cost;
            //cout << char(es[i].from+65) << "->" << char(es[i].to+65) << "     " << es[i].cost << endl;
        }
        E *= 2;
        bellmanFord(0);
        for(int i = 0; i < V; i++){
            cout << char(i+65) << "      " << d[i] << endl;
        }
    }
    fclose(stdin);
    return 0;
}
