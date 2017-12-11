#include <stdio.h>
#include <iostream>
#include <malloc.h>

using namespace std;

/*
	串的堆储存结构上实现Concat(&T,s1,s2)
*/

// 状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// 状态
typedef int Status;

typedef struct HString
{
	char *ch;
	int len; // 字符串的长度
	HString(){
		ch = NULL;
	}
}HString;

Status StrAssign(HString &T, char * chars); // 生成一个其值等于常量chars的字符串
Status Concat(HString &T, HString s1, HString s2); // 连接两个字符串把他复制到字符串T中
ostream & operator << (ostream &out,const HString &s); // 重载<<运算符

int main()
{      
	HString T,s1,s2;
	StrAssign(s1,(char *)"I AM "); // 对字符串赋值
	StrAssign(s2,(char *)"A GOOD BOY"); // 对字符串赋值
	Concat(T,s1,s2); // 连接
	// 打印
	cout << s1 << endl;
	cout << s2 << endl;
	cout << T << endl;
	return 0;
}

// 生成一个其值等于常量chars的字符串
Status StrAssign(HString &T,char *chars) {
	if(T.ch) free(T.ch); // 先把它置空
	int i = 0;
	while(chars[i++] != '\0');
	i--; // 得到长度
	if(!i) {T.ch = NULL; T.len = 0;} // 是空
	else {
		if(!(T.ch = (char *)malloc(sizeof(char)*i))) exit(OVERFLOW);
		T.len = i;
		for (i = 0; i < T.len; ++i) // 开始复制
		{
			T.ch[i] = chars[i];
		}
	}
	return OK;
}

// 连接两个字符串把他复制到字符串T中
Status Concat(HString &T, HString s1, HString s2) {
	if(T.ch) free(T.ch); // 释放旧的空间
	if(!(T.ch = (char *)malloc(sizeof(char)*(s1.len+s2.len)))) exit(OVERFLOW);// 开辟新内存
	T.len = s1.len+s2.len;
	int i;
	for (i = 0; i < s1.len; ++i) // 连接s1
	{
		T.ch[i] = s1.ch[i];
	}
	int j = i;
	for (int i = 0; i < s2.len; ++i) // 连接s2
	{
		T.ch[j++] = s2.ch[i];
	}
	return OK;
}

// 重载<<运算符
ostream & operator << (ostream &out,const HString &s) {
	if(s.ch) out << s.ch;
	else out << "";
	return out;
}

