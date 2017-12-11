/*************************************************************************
	> File Name: main.cpp
	> Author: 何军 
	> Mail: 1839: Kolakoski
	> Created Time: 2017年10月16日 星期一 19时04分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

const int max_n = 10000005; // 序列的最长的长度
bool kolakoski[max_n]; // 序列,true--1,false--2;


void solve(){
    bool tmp = true;
    kolakoski[1] = true;
    kolakoski[2] = false;
    int i = 2,j = 2;
    while(j < max_n){
        if(kolakoski[j-1]) tmp = false;
        else tmp = true;
        if(kolakoski[i++]){ // 如果这个数是1
            kolakoski[j++] = tmp;
        } else {
            kolakoski[j] = tmp;
            kolakoski[++j] = tmp;
            j++;
        }
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    
    solve(); // 处理
    int T,n;
    cin >> T;
    while(T--){
        cin >> n;
        if(kolakoski[n]) cout << 1 << endl;
        else cout << 2 << endl;
    }

    //fclose(stdin);
    return 0;
}