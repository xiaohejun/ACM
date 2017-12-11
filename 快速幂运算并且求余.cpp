/******************
 *
 *  1102: 高级机密
 * 快速幂运算并且求余
 *
 ******************/
#include <stdio.h>
#include <iostream>

using namespace std;

int mod_pow(int x, int n, int mod){
    int res = 1;
    while(n > 0) {
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

int main()
{   
    freopen("in.txt", "r", stdin);
    int a,b,c;
    while(cin >> a >> b >> c) {
        cout << mod_pow(a,b,c) << endl;
    }
    fclose(stdin);
    return 0;
}