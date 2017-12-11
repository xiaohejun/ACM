/**
 * ------------全排列---------------
 * 问题链接：http://cxsjsxmooc.openjudge.cn/2017t2summerall/003/
 * 问题分析：
 * 			给的字符串已经按照从小到大排列，字符串长度在1-6之间
 * 找到递归的本质。	 
 * 第一个字母下标：0  -- 1
 * 						2
 * 						--
 * 						size-2
 *                1
 *                2
 *               --
 *               size-1
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int M = 8; // 多开一点，防止出错
char str[M];
char permutation[M]; // 排序后的字符串
bool used[M] = {0};
int L = 0; // 字符串长度

void Permutation(int n){
	if (n == L)
	{
		permutation[L] = 0;
		cout << permutation << endl;
	}
	for (int i = 0; i < L; ++i)
	{
		if (!used[i])
		{	
			// 判断这个字母有没有用过
			used[i] = true;
			permutation[n] = str[i];
			// 对下一个进行操作
			Permutation(n+1);
			// 回到没有用过的状态
			used[i] = false;
		}
	}
}
/**
 * 
 *	输入：abc
 *
 *	abc
 *	acb
 *	bac
 *	bca
 *	cab
 *	cba
 */

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
	// 输入一个字符串
	cin >> str;
	L = strlen(str);
	// 排序
	sort(str,str+L);
	// 全排列
	Permutation(0);
	return 0;
}
