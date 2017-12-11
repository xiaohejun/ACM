#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX_N = 1e5;
int a[MAX_N];
int N, m;
bool C(int x) // x是数字之间的差值
{
  int cnt = 0; // 个数
  for(int i = 0; i < N; i++)
  {
    cout << "pos= "<< a+N-lower_bound(a, a+N, a[i]+x) << endl;
    cnt += a+N - lower_bound(a, a+N, a[i]+x);
    if(cnt == 0) break;
  }
  return cnt > m;
}
void solve()
{
  m = N*(N-1)/4; // 得到中位数的位置
  sort(a, a+N); // 排序数组
  int l = 0, r = a[N-1] - a[0];
  while(r - l > 1)
  {
    int mid = (l + r) / 2;
    if(C(mid)) 
      l = mid; // 扩大数字
    else
      r = mid; // 缩小数字
  }
  printf("%d\n", l);
}
int main()
{
  freopen("Median.txt", "r", stdin);
  while(scanf("%d", &N) != EOF)
  {
    for(int i = 0; i < N; i++)
      scanf("%d", a+i);
    solve();
  }
  return 0;
}