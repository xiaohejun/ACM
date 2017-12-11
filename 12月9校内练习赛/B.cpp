#include <bits/stdc++.h>

using namespace std;

string str;
int y,m,d; // 年,月,日

int day[2][12] = {
	{
		31,28,31,30,31,30,31,31,30,31,30,31 // 平年的每个月有几天
	},
	{
		31,29,31,30,31,30,31,31,30,31,30,31 // 润年每个月有几天
	}
};

void solve(){
	int a; // 用于过程中的变量
	y = m = d = 0; // 年,月,日初始化
	int len = str.length(); // 字符串的长度
	for (int i = 0; i < len; ++i) // 处理字符串.把年,月,日,拿出来
	{	
		if(str[i] == '/') continue; // 如果是'/',跳过本次循环
		a = 0; // 每一次运算赋值0
		while(str[i] >= '0' && str[i] <= '9' && i < len) { // 得到数字
		    a += str[i]-'0';
		    a *= 10;
		    i++;
		}
		a /= 10;
		if(y == 0) y = a; // 得到年,月,日
		else if(m == 0) m = a;
		else if(d == 0) d = a;
	}
	int x = 0; // x是0.说明是平年
	int sum = 0; // 计算
	if((y%4 == 0 && y%100 != 0) || y%400 == 0) x = 1; // 4年一润,百年不润,400年再润.如果是润年x=1
	for (int i = 0; i < m-1; ++i) // 加到m-1月
	{
		sum += day[x][i];
	}
	cout << sum+d << endl; // 再加上这个月的天数就是答案
}

int main(){
	//freopen("in.txt", "r", stdin);
	while(cin >> str) { // 输入数据
	    solve(); // 解决
	}
	return 0;
}