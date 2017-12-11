//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 1 << 30;
const int MAX_N = 500+10;
const int MAX_M = 2500+10;
const int MAX_W = 200+10;
int F,N,W,M;

struct edge { int from, to, cost; }; // 边的结构
edge es[MAX_M*2+MAX_W]; // 边
int d[MAX_N]; // 到点的最短距离


void init(){ // 初始化操作
    fill(d, d+N+1, INF);
}


void bellmanFord(int s){ // 从点s到其他点的最短距离
    init();
    d[s] = 0; // 起点距离是0
    while(true){
        bool update = false;
        for(int i = 0; i < M*2+W; i++){ // 如果是无向图的话就是边的两倍
            edge e = es[i]; // 取出每一条边
           // cout << e.from <<" " << e.to << " " << e.cost << endl;
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){ // 更新到点的距离
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(d[s] < 0) break; // 有负圈,更新到小于可以停止
        if(!update) break;
    }
}


int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int s,e,t;
	cin >> F;
	while(F--){
        bool flag = false;
	    cin >> N >> M >> W;
        for(int i = 0; i < M; i++){
            scanf("%d%d%d", &s,&e,&t);
            es[i].from = s; es[i].to = e; es[i].cost = t;
            es[i+M].to = s; es[i+M].from = e; es[i+M].cost = t;
        }
        for(int i = 0; i < W; i++){
            scanf("%d%d%d", &s,&e,&t);
            es[i+M+M].from = s; es[i+M+M].to = e; es[i+M+M].cost = -t;
        }
        for(int i = 1; i <= N; i++){
             bellmanFord(i);
             if(d[i] < 0) {printf("YES\n"); flag = true; break;}
        }
        if(!flag) printf("NO\n");
	}
	return 0;
}
