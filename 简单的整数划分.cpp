/**
* 简单的整数划分问题
* 5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1
* f(n,k)
* 问题分析：对n进行m的划分
* 			1.n=1:一种划分{1}
* 			2.k=1:一种划分,n个1{1,1,1...}
* 			3.n=k:包含n--{n}
* 				  不包含n--对n的所有n-1划分
* 				  f(n,n)=1+f(n,n-1);
* 			4.n<k:f(n,n)
* 			5.n>k:--有k   {k,{n-k}}  f(n-k,k)
* 			      --没k   {} f(n,k-1)
* 			      f(n,k) = 
*/

#include "stdafx.h"
#include<iostream>  
using namespace std;  
  
int f(int n,int k)  
{  
    if (n==1 || k==1)
    {
    	return 1;
    }
    if (n==k)
    {
    	return 1+f(n,n-1);
    }
    if (n<k)
    {
    	return f(n,n);
    }
    if (n>k)
    {
    	return f(n-k,k)+f(n,k-1);
    }
}  
  
int main()  
{  
    int n;  
    while(cin >> n)  
        cout<<f(n, n)<<endl;  
    return 0;  
}  