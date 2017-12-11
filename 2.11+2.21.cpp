#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

/*
	2.11+2.22
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
// 数据元素初始化的内存分配量
#define LIST_INIT_SIZE 100
// 线性表储存空间的增量
#define LIST_INCREMENT 10

// 状态
typedef int STATUS;

/*建立线性表的结构体*/
typedef struct List {
	ElemType *elem;
	int length;
	int listSize;
}List;

// 操作结果，构造一个空的线性表L
STATUS InitList(List &L) {
	// 开辟内存
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	// 如果指针不是空的，说明开辟内存成功
	if (!L.elem) exit(OVERFLOW); // 储存空间分配失败
								 // 如果指针不为空，说明开辟内存成功
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return OK;
}



// 将一x插入位置下标为i的位置上
STATUS InsertElem(List &L, int i, ElemType e) {
	if (i < 0 || i > L.length) return ERROR; // i的值不合法
	if (L.length + 1 > LIST_INIT_SIZE) { // 插入一个数据后，地址不够用，开辟新内存
		ElemType * newbase = (ElemType *)realloc(L.elem, (LIST_INIT_SIZE + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW); // 分配内存失败
		L.elem = newbase; // 得到新的地址
		L.listSize += LIST_INCREMENT; // 链表大小增加
	}
	// 开始插入元素
	ElemType * p = &(L.elem[i]); // p指向i该放的位置
	for (ElemType * q = &L.elem[L.length - 1]; q >= p; q--) *(q + 1) = *q; // i后面的元素往后移动
	*p = e; // 插入
	L.length++; // 插入成功，长度加一
	return OK;
}

// 找到应该插入的位置
int FindFitLocation(List L, ElemType e) {
	int mid; // 中间的位置
	int front = 0, end = L.length - 1;
	if (e > L.elem[end]) return L.length;
	mid = (front + end) / 2;
	while (!(L.elem[mid] >= e && (L.elem[mid - 1] < e || mid - 1 < 0)))
	{
		mid = (front + end) / 2;
		if (e == L.elem[mid]) break; // 等于中间的话，直接返回中间
		if (e < L.elem[mid]) end = mid - 1; // 如果比中间的小，插在前半段
		if (e > L.elem[mid]) front = mid + 1; // 如果比mid还大
	}
	return mid;
}

// 用数组初始化链表
void ArrayList(List &L, ElemType *elem, int length) {
	for (int i = 0; i < length; i++) L.elem[i] = elem[i];
	L.length = length;
}

// 重载运算符，打印顺序表
ostream & operator <<(ostream &o, const List L) {
	for (int i = 0; i < L.length; i++) {
		o << L.elem[i] << " ";
	}
	return o;
}

// 交换两个数
void Swap(ElemType &a, ElemType &b) {
	ElemType tmp = a; a = b; b = tmp;
}


// 就地逆置顺序表
void ReverseList(List &L) {
	int front = 0, end = L.length - 1; // 开始和结束的下标
	int mid = (front + end) / 2;
	while (front != mid) Swap(L.elem[front++], L.elem[end--]);// 前后交换
	Swap(L.elem[front], L.elem[end]); // 确保奇数和偶数个的数组都可以
}

int main()
{
	ElemType a[10] = { 1,9,12,13,22,25,35,36,40,41 };// 用于初始化顺序表
	ElemType e = 34; // 要插入的元素
	List L; // 顺序表
	InitList(L); // 开辟顺序表
	ArrayList(L, a, 10); // 用数组初始化链表
	cout << L << endl; // 插入前打印
	FindFitLocation(L, e);
	InsertElem(L, FindFitLocation(L, e), e); // 适当位置插入元素
	cout << L << endl; // 插入后打印
	ReverseList(L); // 就地逆置
	cout << L << endl; // 就地逆置后打印
	return 0;
}

/*
1 9 12 13 22 25 35 36 40 41
1 9 12 13 22 25 34 35 36 40 41
41 40 36 35 34 25 22 13 12 9 1
*/