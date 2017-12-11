/***
    1830: Is Derek lying?
解题思路：
a=两人回答相同的数目
b=两人回答不同的数目
先假设分数是合理的
1、两人分数较低的分数< a ,说明回答相同的部分有回答错误的，那么两人分数的差值必须比b少才会合理，否则不合理
2、两人分数较低的分数>=a，说明回答相同的部分都是正确的，那么两人回答正确但回答不一样的数目有 x - a + y - a，这个数目必须小于b才合理，不然不合理。

****/

#include<iostream>  
#include<cmath>  
#include<cstdio>  
using namespace  std;  
char xx[80000],yy[80000];  
int main(){  
    int t;  
    scanf("%d",&t);  
    while(t--){  
        int n,x,y;  
        scanf("%d%d%d",&n,&x,&y);  
        scanf("%s",xx);  
        scanf("%s",yy);  
        int a=0;  
        for(int i=0;i<n;i++){  
            if(xx[i]==yy[i])a++;  
        }  
        int b=n-a;  
          
        if(a>=min(x,y)){  
            if(abs(x-y)>b){  
            printf("Lying\n");  
            continue;  
        }  
        else{  
            printf("Not lying\n");  
            continue;  
        }  
        }  
        if(a<min(x,y)){  
            if(x-a+y-a<=b){  
                printf("Not lying\n");  
                continue;  
            }  
            else{  
                printf("Lying\n");  
                continue;  
            }  
        }  
    }  
    return 0;  
}  