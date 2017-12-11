/*
1541 ：拦截导弹

*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int high[26]; // 导弹的高度
int maxLen[26]; // 包含这个位置的长度

int main(int argc, char const *argv[])
{	
	//freopen("in.txt", "r", stdin);
	int k = 1;
	while (cin >> high[k++]){maxLen[k-1] = 1;};
	k -= 2;
	// 计算最多能拦截的导弹数，也就是计算最长的逆序数
	// 1 2 3 2 3 4 5 6
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j < i; j++) {
			if (high[i] <= high[j]) {
				maxLen[i] = max(maxLen[i], maxLen[j]+1); // 取本身自己的和前面的比较的最大的一个数
			}
		}
	}
	cout << * max_element(maxLen + 1, maxLen + k +1) << endl;
	// 最少要多少套系统。也就是计算最长的正序数
	for(int i=1;i<=k;i++) maxLen[i]=1;
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j < i; j++) {
			 if(high[i]>high[j] ) maxLen[i]=max(maxLen[i],maxLen[j]+1);
		}
	}
	cout << * max_element(maxLen + 1, maxLen + k +1) << endl;
	//fclose(stdin);
	return 0;
}
