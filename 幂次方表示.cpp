/**
* ------------幂次方表示---------------
* 
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int bit;


int getBit(int n, int i) {
	// 得到整数的位数
	return (n >> i) & 1;
}


string powerOFtwo(int n) {
	string str = "";
	int i;
	bool first = true;
	for (i = 16; i >= 0; --i)
	{
		bit = getBit(n, i); // 得到n的第i位
		if (bit) // 如果bit是1
		{	
			// 加号是交替出现的
			if (!first) {
				str += "+";
			}
			else first = false;
			switch (i)
			{
			case 0: bit ? (str += "2(0)") : ""; break;
			case 1: str += "2"; break; // 如果是第一位
			default: str += ("2(" + powerOFtwo(i) + ")");
			}
			
		}
	}
	return str;
}



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << powerOFtwo(n) << endl; // 显示n的幂次方
	return 0;
}
