/************************************
 *
 *    求gcd(a,b)。有三种情况：
 *
 *　　1.a,b为偶数，则gcd(a,b)=2*gcd(a/2,b/2)
 *　  2.a为奇数，b为偶数，则gcd(a,b)=gcd(a,b/2)
 *    3.a,b为奇数。假设a>=b，则gcd(a,b)=gcd((a-b)/2,b)
 *　  4.a为0，则返回b
 *
 *
 *
 ***********************************/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>  

using namespace std;

// 欧拉函数
int eular(int n)
{
    int ret=1,i;
    for(i=2; i*i<=n;i ++)
    {
        if(n%i==0)
        {
            n/=i,ret*=i-1;
            while(n%i==0) n/=i,ret*=i;
        }
    }
    if(n>1) ret*=n-1;
    return ret;
}

int main(){
    //freopen("in.txt", "r", stdin);
    // 0和本身  2
    int num,t;
    cin >> t;
    while(t--) {
        cin >> num;
        cout << eular(num)+1 << endl;
    }
    //fclose(stdin);
    return 0;
}
