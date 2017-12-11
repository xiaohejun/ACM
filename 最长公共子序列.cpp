/**
* 引入一个数组，不管它们是否对最终解有用，
* 把所有子问题的解存于该数组中，
* 这就是动态规划法所采用的基本方法。
* 最长公共子序列（“人人为我递归型动归程序”）
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 两个字符串
char sz1[1000];
char sz2[1000];
int maxLen[1000][1000]; // 第一个字符串的前i个字符与第二个字符串的
                        // 前j个字符的最长公共子序列长度
						// 求maxLen[len1][len2];
int main(int argc, char const *argv[])
{	
	// freopen("input.txt", "r", stdin);
	int len1 , len2;
	while (cin >> sz1 >> sz2) // 输入字符串
	{
		len1 = strlen(sz1); len2 = strlen(sz2); // 两个字符串的长度
		for (int i = 0; i <= len1; i++) { maxLen[i][0] = 0;  } // 如果sz2字符串没有字符的话这个值是0
		for (int j = 0; j <= len2; j++) { maxLen[0][j] = 0;  } // 如果sz1字符串没有字符的话这个值是0
		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				if (sz1[i-1] == sz2[j-1]) {
					maxLen[i][j] = maxLen[i-1][j-1] + 1; // 加上这个字符
				}
				else {
					maxLen[i][j] = max(maxLen[i - 1][j], maxLen[i][j - 1]); // 在这两个数字的最大
				}
			}
		}
		cout << maxLen[len1][len2] << endl;
	}
	// fclose(stdin);
	return 0;
}

/*
	输入:
		abcfbc abfcab
		programming contest
		abcd mnp
	输出：4
		  2
		  0
*/
