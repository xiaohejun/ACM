#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

/*
	1229: 密码截获（oj）
*/

bool solve(string str){
	bool ans = false;
	int s = 0,e = str.length()-1,mid = e/2;
	while(s < mid && e > mid){
		if(str[s] != str[e]) break;
		s++;e--;
	}
	if(s == e || str[s] == str[e]) ans = true;
	return ans;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	string str,s;
	int ans = 1;	
	while(cin >> str) {
	    bool flag = false;
	    if(str.length() == 1) ans = 1; 
	    else {
	    	for (int i = str.length(); i >= 2; --i) // 截取的长度
		{
		    	for (int j = 0; j <= str.length()-i; ++j)
		    	{
		    		s = str.substr(j,i); // 截取字符串
		    		//cout << s << endl;
		    		if(solve(s)) {ans = i; flag = true; break;} // 验证字符串
		    	}
		    	if(flag) break;
		}    
	    }
	    cout << ans << endl;
	}
	//fclose(stdin);
	return 0;
}

