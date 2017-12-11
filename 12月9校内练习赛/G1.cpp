#include <bits/stdc++.h>


using namespace std;

const int MAX_N = 20000+10;
int a[MAX_N];

int n,m;

int main(){
   // freopen("in.txt", "r", stdin);
    int tmp;
    int last;
    while(cin >> n >> m) {
       for (int i = 0; i < n+m; ++i) // 把所有数据都存在一个数组中
       {
           cin >> a[i];
       }
       sort(a, a+n+m); // 排序.使用快速排序.这个函数在algorithm中.
       printf("%d", a[0]); // 输出地一个元素
       last = a[0]; // last存上一个输出的数据
       for (int i = 1; i < n+m; ++i) // 判断重复输出数组数据
       {
           if(a[i] != last){
                printf(" %d", a[i]);
                last = a[i];
           }
       }
       printf("\n");
    }
    return 0;
}
