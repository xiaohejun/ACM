/**
* ------------汉诺塔问题-------允许移动----------
* 有一座塔，塔内有三个座A,B,C。A座上有64个盘子，盘子大小不等，大的在下
* 小的在上。有一个人想把这64个盘子从A座移动到C座，但每次只能允许移动一个
* 盘子，并且在移动过程中，3个座上的盘子始终保持在大盘在下，小盘在上。
* 在移动过程中可以利用B座，要求输出移动的步骤。
*
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

/**
 * ----------------以3(A,B,C)作为例子分析----------------------
 *  
 * 3(A,B,C) --->2(A,C,B)--->1(A,B,C)  [1]A->C
 * 						相当于(A,C,B)  [2]A->B
 * 						--->1(C,A,B)  [3]C->B   
 *
 * --------------------相当于(A,B,C)-> [4]A->C
 *          --->2(B,A,C)--->1(B,C,A)  [5]B->A
 *          			相当于(B,A,C)  [6]B->C
 *			            --->1(A,B,C)   [7]A->C
 * 
 */
/**
 * 结果：A->C
 *		A->B
 *		C->B
 *		A->C
 *		B->A
 *		B->C
 *		A->C
 */
// 将src座上的n个盘子，以mid为中转，从src移动到dest
void Hanio(int n, char src, char mid, char dest) {
	if (n == 1) // 如果只有一个盘子,直接将它移动到dest
	{
		cout << src << "->" << dest<<endl;
		return;
	}
	Hanio(n - 1, src, dest, mid); // 将n-1个以dest作为中转先移动到mid
	cout << src << "->" << dest<<endl;
	Hanio(n - 1, mid, src, dest);
	return;
}


int main(int argc, char const *argv[])
{	
	int n;
	cin >> n;
	Hanio(n, 'A', 'B', 'C');
	return 0;
}
/**
 *  输入3
 * 结果：A->C
 *		A->B
 *		C->B
 *		A->C
 *		B->A
 *		B->C
 *		A->C
 */