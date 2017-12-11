#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
  // freopen("in.txt", "r", stdin);
    // 这个枚举方法不推荐,看I1
    int t,n,m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int sum = 0;
        for (int q = 1; q <= n; ++q)
        {
            for (int k = 1; k <= m; ++k) // 高的控制
            {
                for (int i = q; i <= n; ++i) // 宽
                {
                    for (int j = k; j <= m; ++j) // 高
                    {
                        sum++;
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}

