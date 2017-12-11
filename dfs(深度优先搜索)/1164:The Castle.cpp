#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 50+5;
const int MAX_N = 50+5;
int arr[MAX_M][MAX_N];
bool has[MAX_M][MAX_N];
int m,n;
int num,maxsum,sum;

void init(){
    num = sum = 0;
    maxsum = -1;
    memset(has, false, sizeof has);
}

void dfs(int i,int j){
    if(has[i][j] || i < 1 || i > m || j < 1 || j > n) return;
    has[i][j] = true;
    sum++;
    if(!(arr[i][j] & 1))  dfs(i,j-1); // west
    if(!(arr[i][j] & 2))  dfs(i-1,j); // notrh
    if(!(arr[i][j] & 4))  dfs(i,j+1); // east
    if(!(arr[i][j] & 8)) dfs(i+1,j); // south
}

void solve(){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(!has[i][j]) {
                dfs(i,j);
                num++;
                maxsum = max(maxsum, sum);
                sum = 0;
            }
        }
    }
    printf("%d\n%d\n", num, maxsum);
}

int main(){
  //  freopen("in.txt", "r", stdin);
    while(cin >> m >> n){
        init();
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cin >> arr[i][j];
            }
        }
        solve();
    }
    return 0;
}
