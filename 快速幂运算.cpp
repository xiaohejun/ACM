/*************************************************************************
	> File Name: main.cpp
	> Author: 何军 
	> title: 快速幂运算 
	> Created Time: 2017年10月16日 星期一 19时04分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

int pow(int a,int b){
    int r=1,base=a;
    while(b){
            if(b&1) r*=base;
            base*=base;
            cout << base << endl;
            b>>=1;    
    }
      return r;

}


int main(){
    freopen("in.txt", "r", stdin);
    cout << pow(2,11) << endl;
    fclose(stdin);
    return 0;
