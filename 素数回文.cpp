#include <iostream>  
#include <cstdio>  
#include <cstring> 
#include <cmath>

using namespace std; 

typedef long long ll;

const int MAX_L = 100000000+5; // 区间的最大长度
const int MAX_SQRT_B = 10000+5; // 区间右边的最大数开根号
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];
int a[10];

void segment_small(ll a, ll b){
    for(int i = 0; ll(i*i) <= b; i++) is_prime_small[i] = true;
    for(int i = 0; i <= b-a; i++) is_prime[i] = true;

    for(int i = 2; ll(i*i) <= b; i++)
    {
        if (is_prime_small[i])
        {
            for(int j = 2*i; ll(j*j) <= b; j+=i) is_prime_small[j] = false;
            for(ll j = max(2LL, (a+i-1)/i) * i; j <= b; j += i) is_prime[j-a] = false;
        }
    }
}

bool is_num(int i){
    int len = 0;
    while(i) {
        a[len++] = i%10;
        i /= 10;
    }
    if(len == 1) return true;
    int j = 0, k = len-1;
    for (; k > j; j++,k--)
    {
        if(a[j] != a[k]) break;
    }
    if(j == len/2 || j == (len/2)+1) return true;
    return false;
}

int main()  
{   
    //freopen("in.txt", "r", stdin);
    ll a,b;
    int i;
    while(~scanf("%lld%lld", &a, &b)) {
        segment_small(a,b);
        for (i = a; i <= b; ++i)
        {
            if(is_prime[i-a] && is_num(i)) printf("%d\n", i);
        }
    }
    //fclose(stdin);
    return 0;  
}  

