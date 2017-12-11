/******************
 *
 *  1092: 序列输出
 *
 ******************/

#include <iostream>  
#include <cstdio>
#include <queue>


using namespace std;  

struct pos {  
   int i,j;
   pos(int x, int y){
        i = x; j = y;
   }  
   friend bool operator < (pos a, pos b)  
   {  
       return float(a.i)/float(a.j)>float(b.i)/float(b.j);    //x小的优先级高。  
   }  
};  

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}


int main()  
{   
    //freopen("in.txt", "r", stdin);
    int i,j,n,t;
    priority_queue<pos> q; 
    cin >> t;
    while(t--) {
        scanf("%d", &n);
        for (i = 1; i < n; ++i)
        {
            for (j = i+1; j <= n; ++j)
            {
                if(gcd(i,j) == 1) q.push(pos(i,j));
            }
        }
        while(!q.empty()) {
            pos p = q.top();
            q.pop();
            if(q.size() > 0) printf("%d/%d,", p.i, p.j);
            else printf("%d/%d", p.i, p.j);
        }
        printf("\n");
    }
    //fclose(stdin);
    return 0;  
}  