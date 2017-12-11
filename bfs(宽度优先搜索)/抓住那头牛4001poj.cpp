/*************************************************************************
	> File Name: 抓住那头牛4001poj.cpp
	> Author:何军 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 09时48分11秒
    (1) 把初始结点S0放入Open表中
    (2) 如果Open表为空,则问题无解,失败退出
    (3) 把Open表的地一个结点取出放入Closed表,记该结点为n
    (4) 考虑结点n是否为目标结点.若是,则得到问题的解,成功退出
    (5) 若结点n不可以扩展,则转到第二歩
    (6) 扩展结点n,将其不在Closed表和Open表中的子结点(判重)放入
        Open表的尾部,并且为每一个子结点设置指向父结点的指针(或者
        记录结点的层次),然后转向第(2)步.
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX_N = 1000000; // 数轴的最大位置点
bool visited[MAX_N+10]; // 是否被访问过
int N,K; // N农夫位置,K牛的位置
struct pos
{
    int x; // 位置
    int steps; // 步数
    pos(int xx, int s):x(xx),steps(s){}
};
void bfs(){
    queue<pos> q;
    pos p(N,0); // 初始化开始的位置
    q.push(p); // 把开始位置压入队列
    while(!q.empty()){ // 当队列是空的时候还不能达到就是走不到了
        p = q.front();
        q.pop(); // 取出队头
        if(p.x == K){ // 找到目标
            cout << p.steps << endl;
            return;
        }
        // 扩展结点该结点
        if(p.x-1 >= 0 && p.x-1 <= MAX_N && !visited[p.x-1]){
            q.push(pos(p.x-1, p.steps+1));
            visited[p.x-1] = true;
        }    
        if(p.x+1 >= 0 && p.x+1 <= MAX_N && !visited[p.x+1]){
            q.push(pos(p.x+1, p.steps+1));
            visited[p.x+1] = true;
        }    
        if(p.x*2 >= 0 && p.x*2 <= MAX_N && !visited[p.x*2]){
            q.push(pos(p.x*2, p.steps+1));
            visited[p.x*2] = true;
        }    
    }
    return ;
}

int main(){
    freopen("in.txt", "r", stdin);
    while(cin >> N >> K){
        memset(visited, false, sizeof(visited)); // 初始化成都没有访问过
        bfs(); // 开始宽度优先搜索
    }
    fclose(stdin);
    return 0;
}
