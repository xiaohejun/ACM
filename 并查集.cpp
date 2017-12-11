/*******************
 *
 *    并查集
 *
 *
 ******************/
#include <stdio.h>

const int MAX_N = 1000;

int par[MAX_N]; // 父亲节点
int rank[MAX_N]; // 树的高度

// 初始化N个元素
void init(int n){
    for(int i = 0; i < n; i++){
        pair[i] = i; // 初始化每个点都是根节点
        rank[i] = 0; // 高度是0
    }
}

// 查询树的根
int find(int x){
    if(pair[x] == x) return x; // 本身就是根
    else {
        return pair[x] = find(pair[x]); // 往上找根
    }
}

// 合并x和y所在的集合
void unite(int x, int y){
    x = find(x); // 找到x的根
    y = find(y); // 找到y的根
    if(x == y) return; // 在一个集合
    if(rank[x] > rank[y]){ // x集合的高度高,就把y集合放在x集合中
        par[y] = x;
    } 
    else {
        par[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    
    
    fclose(stdin);
    return 0; 
}
