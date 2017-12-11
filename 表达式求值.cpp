/**
 * 表达式计算，假设计算的值都是整数：
 * 
 * 1.表达式由项组成
 * 2.项由因子组成
 * 3.因子：'(' + 表达式 + ')'
 * 			整数 
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int factor_value(); // 读入因子返回它的值
int term_value(); // 读入一项返回它的值
int expression_value(); // 读入一个表达式返回它的值

int main(int argc, char const *argv[])
{	
	// 打印一个表达式的值
	cout << expression_value() << endl;
	return 0;
}

int expression_value(){
	int result = term_value(); // 得到第一项的值
	bool more = true; // 用于判断是否有更多项
	while(more){
		char op = cin.peek(); // 看这个字符，不从输入流中取走
		if (op=='+' || op=='-')
		{
			cin.get(); // 取走这个字符
			int value = term_value(); // 得到下一项的值
			if(op == '+') result+= value;
			else result-=value;
		} 
		else more = false;
	}
	return result;
}

// 求一个项的值
int term_value(){
	int result = factor_value(); // 得到一个因子的值
	while(true){
		char op = cin.peek();
		if (op=='*' || op=='/')
		{
			cin.get();
			int value = factor_value();
			if (op == '*')
			{
				result *= value;
			} else {
				result /= value;
			}
		} else break;
	}
	return result;
}


int factor_value(){
	int result = 0;
	char c = cin.peek();
	if (c == '(')
	{
		cin.get(); // 把'('拿走
		result = expression_value();
		cin.get(); // 把')'拿走
	}
	else {
		while(isdigit(c)){
			result = 10*result + c - '0'; // 读取字符转换成数字
			cin.get(); // 拿走这个数字
			c = cin.peek();
		}
	}
	return result;
}




