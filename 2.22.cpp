#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

/*
	2.22
*/

// 状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// 数据元素的数据类型
#define ElemType int

// 状态
typedef int Status;

/*线性表的单链表储存结构*/
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

// 初始化一个带头节点的单链表
void InitList(LinkList &L)
{ /* 操作结果：構造一个空的線性表L */
	L = (LinkList)malloc(sizeof(struct LNode)); /* 產生头结點，並使L指向此头结點 */
	if (!L) /* 存儲分配失敗 */
		exit(OVERFLOW);
	L->next = NULL;
}

void DestroyList(LinkList &L)
{ /* 初始條件：線性表L已存在。操作结果：销毁線性表L */
	LinkList q;
	while (L)
	{
		q = L->next;
		free(L);
		L = q;
	}
}

// 创建单链表
Status CreateList(LinkList &L,int n) {
	LNode *node, *p; // 节点
	for (int i = n; i > 0; i--) {
		node = (LinkList)malloc(sizeof(LNode)); // 开辟几点
		if (!node) exit(OVERFLOW); // 分配内存失败
		cin >> node->data; // 输入数据
		node->next = L->next;
		L->next = node;
	}
	return 1;
}

// 反转链表
Status ListReverse(LinkList &L) {
	LNode *p,*r;
	p = L->next;  //p为工作指针，从第一个元素结点开始
	L->next = NULL;  //先将头结点L的next域置为NULL
	while (p != NULL) {  //依次将元素结点摘下
		r = p->next;  //暂存p的后继
		p->next = L->next;  //将p结点插入到头结点之后
		L->next = p; // 相当于从后往前插入节点
		p = r;
	}
	return 1;
}

// 打印链表
void PrintList(const LinkList &L) {
	LinkList S;
	S = L;
	while (S->next != NULL)
	{
		S = S->next;
		cout << S->data << " ";
	}
	cout << endl;
}

/*主函数*/
void main() {
	//freopen("in.txt","r",stdin);
	LinkList L;
	InitList(L); // 创建一个带头节点的链表
	CreateList(L,10); // 输入值
	PrintList(L); // 打印
	ListReverse(L); // 就地逆置
	PrintList(L); // 打印
	DestroyList(L); // 销毁链表
	//fclose(stdin);
}

/*
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10
*/