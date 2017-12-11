/*
   这道题看郭炜的课程熄灯问题就会明白
   第一行的状态确定.后面的状态就确定
*/
#include <iostream>
# include <bits/stdc++.h>
using namespace std;

const int N = 4;
char orStatus[N]; // 开始状态,一个字符串8位，可以装
char chStatus[N]; // 变化的状态
char ansStatus[N]; // 结果的状态
const int INF = 10000; // 操作最多是64,给个最大值


// 得到第i位
int getBit(char c, int i) {
	return (c >> i) & 1;
}

// 设置第i位的值是x,x是0或者1
void setBit(char &c, int i, int x) {
	if (x) c |= (1 << i); // 如果x是1，0|1=1,1|1=1
	else c &= ~(1 << i); // x是0,1&0==,0&1=0
}

// 翻转第i位
void flipBit(char &c, int i) {
	c ^= (1 << i); // 1^1=0,0^1=1,实现了翻转
}

int getAns(char *ansStatus) { // 得到答案
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (getBit(ansStatus[i], j)) count++;
		}
	}
	return count;
}

int main()
{
	//freopen("in.txt","r",stdin);
	// 输入原始状态
	char status;
	int minAns = INF; // 最小得操作次数
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> status; // 输入状态
			// 黑色是0,白色是1
			(status == 'b') ? setBit(orStatus[i], j, 0) : setBit(orStatus[i], j, 1);
			//cout << getBit(orStatus[i],j);
		}
		//cout << endl;
	}
	// 第一行有16种可能
	for (int t = 0; t < 2; t++) {
		for (int n = 0; n < 16; n++) {
			int switchs = n; // 开关
			memcpy(chStatus, orStatus, sizeof(chStatus)); // 复制状态
			for (int i = 0; i < N; i++) { // 行
				ansStatus[i] = switchs; // ansStatus记录操作
				for (int j = 0; j < N; j++) { // 列翻转
					if (getBit(switchs, j)) { // 1代表翻这个
						flipBit(chStatus[i], j); // 翻转自己
						if (j > 0) { // 列数大于0,翻转左边
							flipBit(chStatus[i], j - 1);
						}
						if (j < 3) { // 列数小于3,翻转右边
							flipBit(chStatus[i], j + 1);
						}
					}
				}
				// 行翻转,0 0 0 0
				if (i < 3) { // 0 1 2行得下一行需要翻转,因为下一行得操作根据上一行决定，所以上一行翻转工作已经做了
					chStatus[i + 1] ^= switchs; // 1^1=0,0^1=1,实现了翻转
				}
				
				if(t == 0) switchs = chStatus[i]; // 下一行的按法,（全变黑，上一行是1，下一行就得按1）
				else switchs = chStatus[i] ^ 15;   //（全变白，上一行是0，下一行就得按1）
			}
			if ((chStatus[N - 1] == 0 && t == 0) || (chStatus[N - 1] == 15 && t == 1)) {
				//cout << (int)chStatus[N - 1] << endl;
				//cout << "n=" << n << endl;
				minAns = min(minAns,getAns(ansStatus));
				//cout << t << " " << minAns << endl;
			    // break;
			}
		}
	}
	if(minAns == INF) cout << "Impossible" << endl;
	else cout << minAns << endl;
	//fclose(stdin);
	return 0;
}

