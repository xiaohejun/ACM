/********************************
*   prim
*
*********************************/
#include <bits/stdc++.h>
using namespace std;


const int MAX_N = 2000+10;
const int INF = 1 << 30;

char card[MAX_N][8];
int mincost[MAX_N];
int cost[MAX_N][MAX_N];
bool used[MAX_N];
int N;


int length(int i, int j){
    int ans = 0;
    for(int k = 0; k < 7; k++){
        if(card[i][k] != card[j][k]) ans++;
    }
    return ans;
}

void init(){
    memset(used, false, sizeof used);
    for(int i = 0; i < N; i++){
        mincost[i] = INF;
        for(int j = 0; j < N; j++)
            cost[i][j] = INF;
    }
}

int prim(){
    int res = 0;
    mincost[0] = 0;
    while(true){
        int v = -1;
        for(int u = 0; u < N; u++){
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
        if(v == -1) break;
        res += mincost[v];
        used[v] = true;
        for(int u = 0; u < N; u++){
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}


int main(){
    //freopen("in.txt", "r", stdin);
    while(cin >> N && N){
        init();
        for(int i = 0; i < N; i++){
            cin >> card[i];
        }
        for(int i = 0; i < N-1; i++){
            for(int j = i+1; j < N; j++){
                cost[i][j] = cost[j][i] = length(i,j);
            }
        }
       printf("The highest possible quality is 1/%d.\n", prim());
    }
   // fclose(stdin);
    return 0;
}

