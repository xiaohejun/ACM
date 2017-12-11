#include "stdafx.h"
/*
1385: 李白打酒
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//char or[16];
char ch[16];
bool used[16] = { false };

/*
// 从第n个位置开始插入x个a
void solve(int n, int x) {
	if (x == 0) {
		cout << ch + 1 << endl;
		return;
	}
	for (int i = n; i <= 14; i++) {
		if (!used[i]) { // 如果这个位置没有用过
			ch[i] = 'a';
			solve(n+1, x-1); // 从下一个位置开始插入x-1个a
		}
		// 如果这个位置用过了
		solve(n+1, x); // 下一个位置开始插入x个a
		used[i] = false;
	}
}
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	//memset(or,98,sizeof(or));
	memset(ch , 98, sizeof(ch));
	//solve(1,5); // 从第一个位置开始插入5个a
	for (int i = 1; i <= 10; i++) {
		if (!used[i]) ch[i] = 'a';
		for (int j = i+1; j <= 11; j++) {
			if (!used[j]) ch[j] = 'a';
			for (int k = j+1; k <= 12; k++) {
				if (!used[k]) ch[k] = 'a';
				for (int l = k+1; l <= 13; l++) {
					if (!used[l]) ch[l] = 'a';
					for (int m = l+1; m <= 14; m++) {
						if (!used[m]) ch[m] = 'a';
						cout << ch + 1 << endl;
						used[m] = false;
						ch[m] = 'b';
					}
					used[l] = false;
					ch[l] = 'b';
				}
				used[k] = false;
				ch[k] = 'b';
			}
			used[j] = false;
			ch[j] = 'b';
		}
		used[i] = false;
		ch[i] = 'b';
	}
   // fclose(stdin);
	return 0;
}
