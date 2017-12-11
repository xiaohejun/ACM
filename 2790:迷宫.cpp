#include <iostream>
#include <stdio.h>
using namespace std;

// 2790:迷宫

char c[100][100];
int n;
int f(int x,int y)
{
    if(c[x][y]=='.')
    {
        c[x][y]='#';
        return f(x-1,y)+f(x+1,y)+f(x,y-1)+f(x,y+1);
    }
    if(x<0||x>=n||y<0||y>=n||c[x][y]=='#')
    return 0;
}
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int ha,la,hb,lb,i;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>c[i];
        cin>>ha>>la>>hb>>lb;
        if(c[ha][la]=='#'||c[hb][lb]=='#')
        {
            cout<<"NO"<<endl;
            continue;
        }
        f(ha,la);
        if(c[hb][lb]=='#')
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        }
    return 0;
}