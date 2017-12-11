/* 称硬币
 * 有12枚硬币，其中有11枚真币和1枚假币
 * 	假币和真币重量不同，但是不知道假币比真币轻还是重		
 * 	现在，用一架天平称了这些币三次，告诉你称的结果		
 *  找出假币并且确定假币是轻是重（数据一定能找出来）
 */
#include <iostream>
#include <cstring>
using namespace std;
char Left[3][7]; // 三次称量，每一边最多放6个
char Right[3][7];
char result[3][7];
bool isFake(char c, bool light);

int main(int argc, char const *argv[])
{
	int t;
	cin>>t; // 输入要测试的数据组数
	while(t--)
	{	
		// 输入左右两边的硬币表示，用字母A到L
		for (int i = 0; i < 3; ++i)
		{
			cin>>Left[i]>>Right[i]>>result[i];
		}
		// 判断是不是假的，并且是轻还是重
		for (char c = 'A'; c <= 'L'; ++c)
		{
			if (isFake(c, true)) { // 是假的，并且是轻的
				cout<<c<<" is the counterfeit coin and it is light"<<endl;
				break;
			} else if (isFake(c, false)) { // 是假的，并且是重的
				cout<<c<<" is the counterfeit coin and it is heavy"<<endl;
				break;
			}
		}
	}
	return 0;
}
// 判断是不是假的
bool isFake(char c, bool light)
{	
	bool flag=true;
	char *pLeft,*pRight; // 两边的字符串
	for (int i = 0; i < 3; ++i)
	{	
		// 赋值
		if (light) {
			pLeft = Left[i];
			pRight = Right[i];
		} else {
			pLeft = Right[i];
			pRight = Left[i];
		}
		// 判断
		switch(result[i][0]) // 天平右边的情况
		{
			case 'u':if (strchr(pRight,c) == NULL)
						flag=false;
					break;
			case 'e':if (strchr(pRight,c) != NULL || strchr(pLeft,c) != NULL)
						flag=false;
					break;
			case 'd':if (strchr(pLeft,c) == NULL)
						flag=false;
					break;
		}
	}
	return flag;
}

/*
1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even
K is the counterfeit coin and it is light
 */