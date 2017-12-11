
using namespace std;

typedef pair<int, int> P; // pair自己百度
P p[55];

int main(int argc, char const *argv[])
{
   //freopen("in.txt", "r", stdin);
    int t,N;
    int a,b;
    cin >> t;
    while(t--) { // 输入测试组数
        cin >> N; // 输入N
        for (int i = 0; i < N; ++i)
        {   
            cin >> p[i].first >>  p[i].second;
        }
        sort(p, p+N); /// 排序
        for (int i = 0; i < N; ++i) // 输出
        {
            a = p[i].first;
            b = p[i].second;
            for (int j = 0; j < b; ++j)
            {
                printf(">+");
                for (int k = 0; k < a-2; ++k)
                {
                    printf("-");
                }
                printf("+>\n");
            }
            printf("\n");
        }
    }
    return 0;
}

