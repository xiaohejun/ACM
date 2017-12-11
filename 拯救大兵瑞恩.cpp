#include<iostream>  
#include<cstring>  
#include<cstdio>  
#include<queue>  
using namespace std;  
const int nodes=15;  // 最大的情况
int n,m,p;  
bool wall[nodes][nodes][nodes][nodes];  // [x1][y1] 和 [x2][y2]之间是墙(true)  没有墙(false)
int door[nodes][nodes][nodes][nodes];  // [x1][y1] 和 [x2][y2]之间是门
int key[nodes][nodes];  // 钥匙在的位置
bool vis[1<<12][nodes][nodes];  // 拿着[某种]钥匙访问过[x][y]
int dir[4][2]={1,0,0,1,0,-1,-1,0};  // 四个方向
struct node  // 房间
{  
    int x,y;  // 位置
    int sta;  // 拥有的钥匙
    int tim;  // 走过的步数
};  
void init()  
{  
    memset(wall,false,sizeof(wall));  // 初始化都没有墙
    memset(door,0,sizeof(door));  // 初始化都没门
    memset(key,0,sizeof(key));  // 没有钥匙
}  
void bfs()  // 开始宽度优先搜索
{  
    memset(vis,false,sizeof(vis));  // 都没有访问过
    node head,nxt;  // 在的房间  走向的下一个房间
    queue<node> q;  // 走过的房间队列
    head.x=1;head.y=1;head.sta=0;head.tim=0;  // 初始化第一个结点
    if(key[1][1])  // 在第一个房间有没有钥匙
    {  
        head.sta |= key[1][1];  
    }  
    q.push(head);  // 访问过的结点入队列
    vis[head.sta][1][1]=true;  // 访问过
    while(!q.empty())  // 直到队列是空退出
    {  
        head=q.front();  // 得到队头
        q.pop();  
        cout << head.x << " " << head.y << endl;
        if(head.x==n && head.y==m)  // 走到终点
        {  
            printf("%d\n",head.tim);  // 打印步数
            return;  
        }  
        for(int i=0;i<4;i++)  // 四个方向走
        {  
            nxt.x = head.x+dir[i][0];  // 开始走
            nxt.y = head.y+dir[i][1];  
            nxt.tim = head.tim+1;  // 步数加上
            nxt.sta = head.sta;  // 钥匙
            if(wall[head.x][head.y][nxt.x][nxt.y]) continue;  // 两个位置之间有没,换一个方向
            if(nxt.x<1 || nxt.x>n || nxt.y<1 || nxt.y>m) continue;  // 下一个方向超出范围
            int dn = door[head.x][head.y][nxt.x][nxt.y];  // 之间有没有门
            if(dn)  // 有门
            {  
                if(!(1<<(dn-1) & nxt.sta)) continue;  // 没有钥匙
            }  
            if(key[nxt.x][nxt.y])  // 这个位置有钥匙
            {  
                nxt.sta |= key[nxt.x][nxt.y];  // 拿走钥匙
            }  
            if(!vis[nxt.sta][nxt.x][nxt.y])  // 没有拿着钥匙走过
            {  
                vis[nxt.sta][nxt.x][nxt.y]=true;  // 标记访问过
                q.push(nxt);  // 加入队列
            }  
        }  
    }  
    printf("-1\n");  // 走不到
    return;  
}  
int main()  
{  
    freopen("in.txt", "r", stdin);
    while(~scanf("%d%d%d",&n,&m,&p)) // 输入行,列,门的种类 
    {  
        init();  // 初始化
        int K;  // 门和墙的总个数
        scanf("%d",&K);  
        for(int i=1;i<=K;i++)  // 输入有们和有墙的两个结点
        {  
            int x1,y1,x2,y2,g;  
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);  
            if(!g) wall[x1][y1][x2][y2]=wall[x2][y2][x1][y1]=true;  
            else door[x1][y1][x2][y2]=door[x2][y2][x1][y1]=g;  
        }  
        int S;  // 输入钥匙总数
        scanf("%d",&S);  
        for(int i=1;i<=S;i++)  // 输入钥匙在的位置
        {  
            int x,y,z;  
            scanf("%d%d%d",&x,&y,&z);  
            key[x][y]|=1<<(z-1);  
        }  
        bfs();  
    }  
    fclose(stdin);
    return 0;  
}
