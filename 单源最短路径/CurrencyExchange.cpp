#include <bits/stdc++.h>

using namespace std;

const double INF = 1e-6;
const int MAX_S = 100+10;
const int MAX_N = 100+10;
const int MAX_M = 100+10;
const int MAX_V = 1000+10;
int N,M,S; //
double V;

struct edge{
    int to;
    double rate,comm;
    edge(int t, double r, double c):to(t), rate(r), comm(c){}
};
vector<edge> G[MAX_N];
double d[MAX_N];

double cal(double money, double comm, double rate){ // 计算
    return (money-comm)*rate;
}

void init(){ // 初始化操作
    fill(d, d+N+1, INF);
    for(int i = 0; i <= N; i++){
        G[i].clear();
    }
}

void solve(int s){
    queue<int> que; // 工作队列
    int from;
    que.push(s); // 把开始结点加入队列
    d[s] = V; // 地一个结点的值就是有的钱
    while(!que.empty()){
        from = que.front(); que.pop(); // 从队列中取出
        for(int i = 0; i < G[from].size(); i++){ // 从初始点开始如果可以更新周围的结点
            edge e = G[from][i];
            if(cal(d[from], e.comm, e.rate)  > d[e.to]) { // 如果可以更新
                d[e.to] = cal(d[from], e.comm, e.rate); // 计算更新
                que.push(e.to); // 把更新过的结点加入队列
            }
        }
        if(d[s] > V) {printf("YES\n"); return ;} // 如果升值了,就输出
    }
    printf("NO\n"); // 不可能
}


int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
	int x,y;
       double r1,c1,r2,c2;
	while(cin >> N >> M >> S >> V){
        init();
        for(int i = 0; i < M; i++){
            scanf("%d%d%lf%lf%lf%lf", &x,&y,&r1,&c1,&r2,&c2);
            G[x].push_back(edge(y,r1,c1)); // 输入图
            G[y].push_back(edge(x,r2,c2));
        }
        solve(S);
	}
	return 0;
}
