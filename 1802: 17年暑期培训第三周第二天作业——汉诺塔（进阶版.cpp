#include <cstdio>
#include <iostream>
using namespace std;

void dg(char src, char mid, char dest, int n, int &step)
{
    if(n <= 0) return;
    if(n == 1) {
        printf("%c->%c\n", src, mid);
        printf("%c->%c\n", mid, dest);
        step+=2;
        return;
    }
    dg(src, mid, dest, n-1, step);
    dg(src, mid, dest, 1, step);
    dg(mid, src, dest, n-1, step);
    return;
}
int main()
{   
    freopen("in.txt", "r", stdin);
    int n, step = 0;
    while(~scanf("%d", &n) && n) {
        step = 0;
        dg('A', 'B', 'C', n, step);
        printf("%d\n", step);
    }
    fclose(stdin);
    return 0;
}