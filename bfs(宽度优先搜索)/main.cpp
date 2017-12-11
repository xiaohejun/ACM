/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 17时55分00秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;

const int MAX_M = 200;
const int MAX_N = 200;
char map[MAX_M+10][MAX_N+10];
bool visited[MAX_M+10][MAX_N+10]; // 有没有被访问过
int M,N,T; // M行N列T个查克拉
int go[4][2] = { // 走四个方向
    {1,0}, // 右
    {-1,0}, // 左
    {0,1}, // 上
    {0,-1} // 下
};

struct Pos
{
    int x,y; // 所在的位置
    int steps; // 走的步数
    int has; // 有的查克拉个数
    Pos(int x, int y, int steps, int has){ // 构造函数
        x = x; y = y; steps = steps; has = has;
    }
};

void bfs(int x, int y, int sx, int sy){ // 从(x,y)到(sx,sy)
    queue<Pos> q;
    Pos p(x,y,0,T); // 初始化起点
    q.push(p); // 入栈
    while(!q.empty()){
        p = q.front(); // 取出队头元素
        q.pop();
        if(p.x == sx && p.y == sy){ // 如果走到了终点，就退出
            cout << p.steps << endl; // 输出结果
            return;
        }
        for (int i = 0; i < 4; ++i) // 走四个方向
        {
            int nx = go[i][0]; // 走下一个结点
            int ny = go[i][1];
            if(nx >= 0 && nx < M && ny >= 0 && ny < N){ // 不超出走的范围
                if(!visited[nx][ny]){ // 如果这个结点访问过
                    if(map[nx][ny]=='*'){
                        q.push(Pos(nx,ny,p.steps+1,p.has)); // 入栈
                        visited[nx][ny] = true; // 标记成访问过
                    } else if(map[nx][ny] == '#' && p.has > 0){
                        q.push(Pos(nx,ny,p.steps+1,p.has-1)); // 入栈
                        visited[nx][ny] = true; // 标记成访问过
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{   
    freopen("in.txt","r",stdin);
    int x,y,sx,sy;
    while(cin >> M >> N >> T){
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> map[i][j];
                if(map[i][j]=='@') {x=i;y=j;} // 起点位置
                if(map[i][j]=='+') {sx=i;sy=j;} // 终点位置
            }
        }
        bfs(x,y,sx,sy); // 开始宽搜
    }
    fclose(stdin);
    return 0;
}

