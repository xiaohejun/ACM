#include <bits/stdc++.h>


using namespace std;

int n,m;

int main(){
    // 这个方法不推荐.看G1
    //freopen("in.txt", "r", stdin);
    int b;
    while(cin >> n >> m) {
        set<int> a; // 集合
        for (int i = 1; i <= n+m; ++i)
        {
            cin >> b;
            a.insert(b);
        }
        set<int>::iterator it;
        for (it = a.begin(); it != a.end();)
        {
            printf("%d",*it);
            if(++it != a.end()) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
