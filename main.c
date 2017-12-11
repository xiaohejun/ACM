#include <stdio.h>
#include <malloc.h>

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

typedef struct
{
	char *ch;
	int len; // 字符串的长度
}HString;

Status StrAssign(HString &T, char * chars); // 生成一个其值等于常量chars的字符串
Status Concat(HString &T, HString s1, HString s2); // 连接两个字符串把他复制到字符串T中
//ostream operator << (ostream &out,const HString &s); // 重载<<运算符

int main()
{      
	//freopen("in.txt", "r", stdin);
	HString T,s1,s2;
	StrAssign(s1,""); // 对字符串赋值
	StrAssign(s2,"GOOD BOY"); // 对字符串赋值
	cout << s1.ch << endl;
	cout << s2.ch << endl;
	//fclose(stdin);
	return 0;
}

// 生成一个其值等于常量chars的字符串
Status StrAssign(HString &T,const char *chars) {
	if(T.ch) cout << "不是空" << endl; // 先把它置空
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

	return OK;
}
/*
// 重载<<运算符
ostream operator << (ostream &out,const HString &s) {
	out << s.ch;
	return out;
} */

