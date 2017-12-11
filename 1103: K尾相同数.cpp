/******************
 *
 *  1103: K尾相同数
 *
 ******************/

#include <iostream>  
#include <cstdio>
#include <cstring>


using namespace std;  



int main()  
{   
   // freopen("in.txt", "r", stdin);
    int k,sum;
    while(cin >> k) {
        bool flag = false;
        int a[1001];
        memset(a, 0, sizeof(a));
        if(k >= 1000) {
            flag = true;
            k %= 1000;
        }
        int i,s=1;
        for (i = 1; i < 1002; ++i)
        {
            s *= k; // 次方
            if(flag || s >= 1000) {
                flag = true;
                s %= 1000;
                if(a[s] != 0){
                    sum = a[s]+i;
                    break;
                } else a[s] = i;
            }
        }
        cout << sum << endl;
    }
   // fclose(stdin);
    return 0;  
}  