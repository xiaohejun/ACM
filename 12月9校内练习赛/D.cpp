#include <bits/stdc++.h>


using namespace std;


double m,a,b,c;

int main(){
    //freopen("in.txt", "r", stdin);
    // 这个题目的坑就是题目没有说数据类型.所以数据类型可能是小数
    cin >> m;
    while(m--) {
        cin >> a >> b >> c; // 输入a,b,c
        if(a+b > c && a+c > b && b+c > a && a > 0 && b > 0 && c > 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}