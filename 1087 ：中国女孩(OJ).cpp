#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int text(string a){  
    int len=a.length();  
  
  
    if(a[len-1]=='0' || a[len-1]=='2' || a[len-1]=='4' || a[len-1]=='6'|| a[len-1]=='8')  
        return 1;  
    else  
        return 0;  
  
}  
string sub(string a,string b){  
     int i,j,k,s,flag=1;  
     int tmpa[10000],tmpb[10000],c[10000];  
     string ans;  
     if(a.size()<b.size()|| (a.size()==b.size() && a.compare(b)<0)){  
        string tmp =a;  
        a=b;  
        b=tmp;  
        flag=0;  
     }  
     while(a.length()>b.length()) b='0'+b;  
     int len=a.length();  
     for(i=0;i<len;i++)  
     {  
        tmpa[i]=a[i]-'0';  
        tmpb[i]=b[i]-'0';  
     }  
     for(i=len-1;i>=0;i--){  
        if(tmpa[i]>=tmpb[i])  
            c[i]=tmpa[i]-tmpb[i];  
        else{  
            c[i]=10+tmpa[i]-tmpb[i];  
            tmpa[i-1]--;  
        }  
     }  
     for(i=0;i<len-1;i++)  
        if(c[i]!=0)  
            break;  
        for(j=i;j<len;j++)  
            ans=ans+(char)(c[j]+'0');  
        if(!flag)  
            ans='-'+ans;  
        return ans;  
  
}  
string division(string str,int x){  
   string ans="";  
   int len=str.length();  
   int y=0;  
   for(int i=0;i<len;i++){  
    ans+=char((y*10+(str[i]-'0'))/x+'0');  
    y=(y*10+(str[i]-'0') )%x;  
   }  
   while(*(ans.begin())=='0' && ans.size()>1)  
      ans.erase(ans.begin());  
   return ans;  
}  
int main()  
  {  
     string s,s1,s2;  
     int l;  
     while(cin>>s){  
       // printf("t=%d\n",t);  
        //printf("t=%d\n",text(s));  
        if(text(s)==1){//如果是偶数  
             s1=division(s,2);//大数相除  
           //  cout<<"s1="<<s1<<endl;  
            if(text(s1)==1){  
                 s2=sub(s1,"1");  
            }  
            else{  
                s2=sub(s1,"2");  
            }  
        }  
        else{  
            //printf("ok\n");  
            s1=sub(s,"1");  
            //cout<<"s1="<<sub(s,"1")<<endl;  
            s2=division(s1,2);  
        }    
        cout<<s2<<endl;  
     }  
  
  }  

