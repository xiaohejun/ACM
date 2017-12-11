#include <bits/stdc++.h>


using namespace std;

int m,n; // [m,n]区间

// vector是可变长度的数组.把每一次得到的答案存在一个可变长度的数组中.也可以定义一个足够长的数组来存取答案
vector<int> solve(){
    vector<int> ans; // 储存答案的数组
    for (int b = m; b <= n; ++b) // [m,n]区间之间的水仙花数
    {   
        vector<int> num; // 存每一个位置上的数字  个 十  百  千
        int x = b; // 分离每一个数字的时候会改变最初数字的值,所以先拿一个变量得到
        while(x) { // 把每一个数字的每一个位置上的数字分离出来.存在一个数组中
            num.push_back(x % 10);
            x /= 10;
        }
        int sum = 0; // 每一个位置上的数字的立方和
        for (int i = 0; i < num.size(); ++i) // 计算每一个位置上的数字的立方和
        {      
            int a = num[i];
            sum += a*a*a;
        }
        if(b == sum) { // 如果满足条件.那么它是水仙花数.把它存在数组中
            ans.push_back(b);
            num.clear(); // 存每一个位置上的数字的数组清空
        }
    }
    return ans; // 返回答案数组
}

int main(){
   // freopen("in.txt", "r", stdin);
    while(cin >> m >> n) { // 输入数据
        vector<int> ans = solve();  // 得到答案
        if(ans.size() == 0) printf("no\n"); // 如果答案数组的长度是0.说明在[m,n]中没有水仙花数
        else { // 有答案.输出答案.注意两个数字之间有空格.最后一个数字后面没有空格.
            for (int i = 0; i < ans.size(); )
            {
                printf("%d", ans[i]);
                if(++i < ans.size()) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}