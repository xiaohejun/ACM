#include <iostream>
#include <cstdio>
using namespace std;

int a,b,R,L,cs;
long hash[10000005];
bool h[33][33][33][100];

long l(int jz,int s)
{
int sum=1;
while (s/jz)
{
s/=jz;
sum++;
}
return sum;
}
long bls(int jz,int length,int s1,int s2)
{
int num=s1;
for (int i=1;i<length;i++)
{
if (i%2) num=num*jz+s2;
else num=num*jz+s1;
}
return num;
}
/*
举例
A1A1(16)
1*1+10*16+1*16*16=1+160+256
1*16^0+A*16^1+1*16^2+A*16^3
=1*16^0+16^1*(A+1*16^1+A*16^2)
=1*16^0+16^1*(A+16^1*(1+A*16^1))
=1+16^1*(A+16^1*(1+A*16^1))
bls(jz,length,s1,s2)=s2+jz*(s1+jz*(s2+jz*(…)))
*/
void Solve(int jz)
{
    int l1,l2;
    l1=l(jz,L);l2=l(jz,R);
    for (int i=l1;i<=l2;i++)
    {
        for (int j=1;j<jz;j++){
            for (int k=0;k<jz;k++)
            {
                if (h[j][k][jz][i]||h[k][j][jz][i]||j==k) continue;
                long number=bls(jz,i,j,k);
                if (number>=L&&number<=R)
                {
                    hash[number]+=2;
                    h[j][k][jz][i]=false;
                    h[k][j][jz][i]=false;
                } else if (number>R) break;//如果算第二位超过范围 接下来的就都超过范围了
        }
    }
}

int main()
{   
    freopen("in.txt", "r", stdin);
    while(cin>>a>>b>>L>>R>>cs){
        for (int i=a;i<=b;i++)
        Solve(i);
        for (int i=L;i<=R;i++) if (hash[i]==cs) cout<<i<<endl;
    }
    fclose(stdin);
    return 0;
}
