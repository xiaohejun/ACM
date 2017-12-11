/************************************
 *
 *    求gcd(a,b)。有三种情况：
 *
 *　　1.a,b为偶数，则gcd(a,b)=2*gcd(a/2,b/2)
 *　  2.a为奇数，b为偶数，则gcd(a,b)=gcd(a,b/2)
 *    3.a,b为奇数。假设a>=b，则gcd(a,b)=gcd((a-b)/2,b)
 *　  4.a为0，则返回b
 *
 *
 *
 ***********************************/


#include <iostream>
#include <cstdio>
#include <cstring>  


using namespace std;

const int power = 4;      // 每次运算的位数为10的power次方，在这里定义为了方便程序实现  
const int base = 10000;      // 10的power次方。  

  
const int MAXL = 11;    //数组的长度。  
  
  
char a[MAXL], b[MAXL];  
struct num  
{  
    int a[MAXL];  
    num() { memset(a, 0, sizeof(a)); }                      //初始化  
    num(char *s)                                            //将一个字符串初始化为高精度数  
    {  
        memset(a, 0, sizeof(a));  
        int len = strlen(s);  
        a[0] = (len+power-1) / power;                       //数的长度  
        for (int i=0, t=0, w; i < len ;w *= 10, ++i)          
        {  
            if (i % power == 0) { w = 1, ++t; }  
            a[t] += w * (s[i]-'0');  
        }  
    }  
    void print()                                            //打印此高精度数  
    {    
        for (int i = a[0]-1; i > 0; --i)  
        printf("%0*d", power, a[i]);    
        //这里"%0*d", power的意思是，必须输出power位，不够则前面用0补足  
        printf("\n");  
    }  
}; 

int gcdBinary(int u, int v){
    u = (u < 0) ? -u : u;
    v = (v < 0) ? -v : v;
    if(u == 0) return v;
    if(v == 0) return u;
    int k =0; // 记录偶数情况递归的次数
    while((u & 1)==0 && (v & 1)==0){ // 如果u,v都是偶数
        u >>= 1; // 除2
        v >>= 1; // 除2
        k++;
    }
    // n或者v至少有一个是奇数
    int t = -v; // 设置成负数，便于后面比较,v是偶数,t就是-v
    if((v & 1)==1){ // v是奇数,t就是u
        t = u;
    }

    while(t){
        while((t & 1)==0){ // t是偶数
            t >>= 1; // 除2,直到t不是偶数
        }
        if(t > 0) u = t; // u > v(最大的数被t的绝对值替换)
        else v = -t; // u < v()
        // u和v都是奇数,u-v是偶数
        t = u - v;
    }
    return u*(1 << k);
}

int main(){
    num a((char *)"123");
    a.print();

    return 0;
}
