
#include <iostream>
#include <cstdio>
#include <cstring>  

using namespace std;


int getBit(int n, int i){
    return (n >> i) & 1;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n,num;
    cin >> n;
    while(n--) {
        scanf("%d", &num);
        for (int i = 31; i >= 0; --i)
        {
            printf("%d", getBit(num, i));
        }
        printf("\n");
    }
    //fclose(stdin);
    return 0;
}
