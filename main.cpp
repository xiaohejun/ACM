#include <stdio.h>

int main()
{
   freopen("in.txt", "r", stdin);
    int n,i;
    float x;
    while(~scanf("%f%d", &x, &n)) {
        for(i = 1; i <= n; i++){
            x *= 1.001;
        }
        printf("%.4f\n", x);
    }
    return 0;
}

