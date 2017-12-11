#include <iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int x[507],y[507];  
int visit[607][607]; // visit[i][j] = 1,表示点(i,j)  
int main()  
{   
    //freopen("in.txt", "r", stdin);
    int n,ans;  
    while(~scanf("%d", &n))  // 要输入几个点
    {  
        ans = 0;  
        memset(visit, 0, sizeof(visit));  // 都没有访问过
        for(int i=0; i<n; i++)  
        {  
            scanf("%d %d",&x[i],&y[i]);  // 输入点的坐标
            x[i] += 100, y[i] += 100;  // 因为点坐标可能是负数，保证点为正数
            visit[x[i]][y[i]]=1;  
        }  
        for(int i = 0; i < n; i++) // 遍历点  
        {  
            for(int j = i+1; j < n; j++)  
            {    // (xa,ya)是(xi,yi)和(xj,yj)的中点
                double xa=(x[i]+x[j])/2.0;  
                double ya=(y[i]+y[j])/2.0;
                // xb是中点到xi的横向距离,yb是中点到yi的纵向距离
                double xb=xa-x[i];  
                double yb=ya-y[i];  
                // 因为比如(2,3)和(4,2)这样的两个点是不存在正方形的;
                //      
                if((int)(xa+yb) != xa+yb || (int)(ya-xb) != ya-xb || (int)(xa-yb) != xa-yb || (int)(ya+xb) != ya+xb)  
                    continue;  
                if((int)(xa+yb) >= 0 && (int)(ya-xb) >= 0 && (int)(xa-yb) >= 0 && (int)(ya+xb) >= 0 && visit[(int)(xa+yb)][(int)(ya-xb)] && visit[(int)(xa-yb)][(int)(ya+xb)])  
                {  
                    ans++;  
                }  
            }  
        }  
        printf("%d\n", ans/2);  
    }  
    //fclose(stdin);
    return 0;  
}  

