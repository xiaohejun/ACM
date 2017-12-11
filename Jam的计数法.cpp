#include <stdio.h>

int s,t,w;
char a[100];
int dg(int m)
{
    if(m<0){return 0;}
    if((a[m]+=1)>'a'+t-(w-m))
    {
        if(dg(m-1)==0)
            return 0;
        if(m==0)
        a[m]='a'+s-1;
        else a[m]=a[m-1]+1;
        
    }
    return 1;
}
int main()
{
    int i;
    scanf("%d %d %d",&s,&t,&w);
    scanf("%s",a);
    for(i=1;i<=5;i++)
    {
        if(dg(w-1))
        printf("%s\n",a);
    }
    return 0;
}