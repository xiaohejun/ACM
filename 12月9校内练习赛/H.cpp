#include <bits/stdc++.h>


using namespace std;

int gcd(int m , int n){ // 求最大公约数
    return n==0 ? m : gcd(n, m%n);
}

int lcm(int m, int n){ // 球最小公倍数
    return m*n/gcd(m,n);
}

int T;
int a,b,c,d;

int main(){
  //  freopen("in.txt", "r", stdin);
    cin >> T;
    while(T--) {
        cin >> a >> b >> c >> d; // 输入数据
        int fm = lcm(b,d); // 分母
        int fz = a*(fm/b) + c*(fm/d); // 分子
        int g = gcd(fm,fz); // 分母和分子的最小公倍数
        fm /= g; // 约分
        fz /= g; // 约分
        cout << fz << " " << fm << endl; // 输出结果
    }
    return 0;
}