#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
string str;

LL cal(LL a, char c, LL b){
    switch(c){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '%': return a%b;
    }
}

bool C(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

void solve(){
    LL num[3];
    LL a = 0;
    int cur = 0;
    char c;
    int len = str.length();
    for (int i = 0; i < len; ++i)
    {
        if(C(str[i])) {c = str[i]; continue;}
        while((str[i] >= '0' && str[i] <= '9') && i < len) {
            a += (str[i]-'0');
            a *= 10;
            i++;
        }
        a /= 10; 
        if(a != 0) {num[cur++] = a; a = 0;}
    }
    printf("%lld\n", cal(num[0], c, num[1]));
}

int main(){
    //freopen("in.txt", "r", stdin);
    getline(cin, str);
    solve();
}
