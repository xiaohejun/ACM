#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
  // freopen("in.txt", "r", stdin);
    // 仔细看就发现这个相当于乘法分配率
    int t,n,m;
    int a,b;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int a = n*(n+1)/2; // 高
        int b = m*(m+1)/2; // 宽
        cout << a*b << endl;
    }
    return 0;
}

