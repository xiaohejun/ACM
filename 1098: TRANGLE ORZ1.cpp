/******************
 *
 *  1098: TRANGLE ORZ1
 *
 ******************/
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10000+10;
int li[MAX_N];

int main()
{   
    //freopen("in.txt", "r", stdin);
    int T,N;
    int first,second,three,ans,pre; // 三条边
    cin >> T;
    while(T--) {
        ans = 0;
        cin >> N;
        for (int i = 1; i <= N; ++i) // 输入数据
        {
            scanf("%d", &li[i]);
        }
        sort(li, li+N); // 从小到大排序
        for (int first = 1; first <= N-2; ++first) // first
        {
            for (int second = first+1; second <= N-1; ++second) // second
            {   
                pre = 0;
                for (int three = second+1; three <= N; ++three) // three
                {   
                    if(pre == li[three]) continue; // 跳过
                    else pre = li[three];
                    if(li[first]+li[second] > li[three]) {cout << li[first] << " " << li[second] << " " << li[three] <<endl; ans++;}; // 满足条件
                }
            }
        }
        printf("%d\n", ans);
    }
    //fclose(stdin);
    return 0;
}