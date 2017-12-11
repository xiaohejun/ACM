/**
 * 八皇后问题是一个以国际象棋为背景的问题：如何能够在8×8的国际象
 * 棋棋盘上放置八个皇后，使得任何一个皇后都无法直接吃掉其他的皇后？
 * 为了达到此目的，任两个皇后都不能处于同一条横行、纵行或斜线上。
 * 八皇后问题可以推广为更一般的n皇后摆放问题：这时棋盘的大小变为n×n，
 * 而皇后个数也变成n。当且仅当n = 1或n ≥ 4时问题有解。
 */
/**
 * N皇后问题
 * --------说明：4皇后，两种摆法，第一种，第一行的第2列，第二行的第4列（类推）--
 * 输入：4
 * 输出：2 4 1 3
 * 		3 1 4 2
 */
#include <iostream>
#include <cmath>
using namespace std;

int N; // 棋盘的大小N*N
int queenPos[100]; // 皇后的个数

// 求解N皇后问题
void NQueen(int k){
	int i;
	// 如果K等于N，说明最后一行成功摆好
	if (k == N)
	{
		// 循环输出结果
		for (i = 0; i < N; ++i)
		{
			cout<<queenPos[i]+1<<" ";
		}
		cout<<endl;
	}
	// 如果k不等于N，开始摆放
	for (i = 0; i < N; ++i)
	{
		int j; 
		// 测试如果摆在当前位置是否与之前的冲突
		for (j = 0; j < k; ++j)
		{	
			// queenPos[j]的值存的是当前摆放的列数
			if (queenPos[j] == i || abs(queenPos[j]-i) == abs(k-j))
			{
				break;
			}
		}
		// 到这一步，说明这一行已经摆放成功
		if (j == k)
		{
			queenPos[k] = i;
			NQueen(k+1);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>N; // 输入N皇后，比如
	NQueen(0); // 从第一行开始摆放
	return 0;
}
