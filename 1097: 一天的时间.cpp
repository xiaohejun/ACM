/******************
 *
 *  1097: 一天的时间
 *  离散动态规划,把表画出来就可以找到规律
 ******************/
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;

map<long long,long long> dp[45];

// 计算最大公约数
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

// 计算最小公倍数
long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}

int main()
{   
    //freopen("in.txt", "r", stdin);
    dp[1][1]=1;
    map<long long,long long>::iterator it;
    for(int i=2;i<=40;i++)
    {
        dp[i]=dp[i-1];
        dp[i][i]++;
        for(it=dp[i-1].begin();it!=dp[i-1].end();it++)
        {
            dp[i][lcm(it->first,i)] += it->second;
        }
    }
    int T;
    int iCase=0;
    scanf("%d",&T);
    int n;
    long long m;
    while(T--)
    {
        iCase++;
        scanf("%d%lld", &n, &m);
        long long ans=0; // 答案
        for(it=dp[n].begin(); it!=dp[n].end(); it++)
          if(it->first >= m)
            ans += it->second;
        printf("Case #%d: %lld\n", iCase, ans);
    }
    //fclose(stdin);
    return 0;
}