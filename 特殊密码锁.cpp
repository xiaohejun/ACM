/**
* 有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），
* 按钮有凹/凸两种状态，用手按按钮会改变其状态。
* 然而让人头疼的是，当你按一个按钮时，
* 跟它相邻的两个按钮状态也会反转。
* 当然，如果你按的是最左或者最右边的按钮，
* 该按钮只会影响到跟它相邻的一个按钮。
* 当前密码锁状态已知，需要解决的问题是，
* 你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。
*
* 两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，
* 其中0代表凹，1代表凸。
* 至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
*
* 输入
* 011
* 000
*
* 输出
* 1
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

string orBtn; // 原始的状态
string btn; // 变化的状态
string resultBtn; // 需要变成的状态
int tmp = 0;
int ans = 1e9;
int size = 0;



// 按第i位按钮
void flipBtn(string &c, int i) {
	c[i - 1] = c[i - 1] == '1' ? '0' : '1';
	c[i] = c[i] == '1' ? '0' : '1';
	if ((i + 1) < :: size)
	{
		c[i + 1] = c[i + 1] == '1' ? '0' : '1';
	}
}



int main(int argc, char const *argv[])
{
	// 输入两个状态
	cin >> orBtn;
	cin >> resultBtn;
	btn = orBtn;
	::size = orBtn.size(); // 得到大小
						 // 第一种情况，不按第一颗按钮
	for (int i = 1; i < ::size; ++i)
	{
		// 如果前一个位置何结果要的不相同，那么需要按该按钮
		if (btn[i - 1] != resultBtn[i - 1])
		{
			flipBtn(btn, i); // 按btn的第i颗按钮
			tmp++; // 记数加1
		}
	}
	// 如果这种操作是成功的,那么最后一个按钮的状态是相同的
	if (btn[::size - 1] == resultBtn[::size - 1])
	{
		ans = tmp; // 记录下这个答案
	}

	// 第一种操作成功的话就和第二种操作(第一颗按钮需要按)需要
	// 的次数做比较，取操作次数少的。第一种不成功，那就第二种。
	// 要是第二种操作也不成功，说明不可能
	//--------------------
	// 要按第一颗按钮
	btn = orBtn;
	btn[0] = btn[0] == '1' ? '0' : '1';
	tmp = 1;
	// 按了第一颗按钮，第二颗按钮状态要翻转
	btn[1] = btn[1] == '1' ? '0' : '1';
	// 开始按后面的按钮
	for (int i = 1; i < ::size; ++i)
	{
		// 如果前一个位置何结果要的不相同，那么需要按该按钮
		if (btn[i - 1] != resultBtn[i - 1])
		{
			flipBtn(btn, i); // 按btn的第i颗按钮
			tmp++; // 记数加1
		}
	}
	// 如果这种操作是成功的,那么最后一个按钮的状态是相同的
	if (btn[::size - 1] == resultBtn[::size - 1])
	{
		ans = ans < tmp ? ans : tmp; // 取得次数少的
	}
	// 如果两种操作都不成功
	if (ans == 1e9)
	{
		cout << "impossible" << endl;
	} 
	else
	{
		cout << ans << endl;
	}
	return 0;
}