#include "stdafx.h"
/*
1203 ：人见人爱A + B(OJ)
*/

#include <iostream>
using namespace std;

int t;
long AH, AM, AS; // A时间
long BH, BM, BS; // B时间
long CH, CM, CS; // A+B时间
int carry = 0;

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		cin >> AH >> AM >> AS;
		cin >> BH >> BM >> BS;
		CS = (AS+BS) % 60; // 计算秒
		carry = (AS + BS) / 60;
		CM = (AM + BM + carry) % 60;
		carry = (AM + BM + carry) / 60;
		CH = AH + BH + carry;
		cout << CH << " " << CM << " " << CS << endl;
	}
   // fclose(stdin);
	return 0;
}
