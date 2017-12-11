/******************
 *
 *  1088: Abbreviation
 *
 ******************/

#include <iostream>  
#include <cstdio>  
#include <string.h>  
#include <cctype>  
using namespace std;  
   
int main()  
{   
    //freopen("in.txt", "r", stdin);
    int t;  
    cin>>t;  
    getchar();  
    while(t--){  
        char c[10005];  
        gets(c);  
        string s;  
        int len = strlen(c);  
        for(int i=0;i<len;i++){  
            if(c[i]!=' ')  
                s += (char)toupper(c[i]);  // 转换成大写字符
            else{  
                if(s!="FOR"&&s!="THE"&&s!="AND"&&s.length()>2)  
                    cout<<s[0];  
                s.erase();  // 清除
            }  
        }  
        if(s!="FOR"&&s!="THE"&&s!="AND"&&s.length()>2)  
            cout<<s[0];  
        cout<<endl;  
    }  
    //fclose(stdin);
    return 0;  
}  