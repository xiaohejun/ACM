#include<iostream>  
#include<cmath>  
using namespace std;  

/*
	1772: Add More Zero
*/
int main()  
{  
    long long int m,n,x;  
    m=0;  
    while(cin>>n)  
    {  
        m++;  
        x=int(n*log10(2));  
        cout<<"Case #"<<m<<": ";  
        cout<<x<<endl;  
    }  
    return 0;  
} 