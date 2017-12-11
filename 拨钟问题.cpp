/**
* -----------拨钟问题-----------------
* http://cxsjsxmooc.openjudge.cn/2017t2summerall/002/
* 题目分析：
* 		用最少的移动，9种移动选择来排列组合。2^9-1种可能。
* 		应该拿钟的需要去选择移动的方案。
* 		可以拨动 A:1 2 4
* 				B:1 2 3 5
* 				C:2 3 6
* 				D:1 4 5 7
* 				E:1 3 5 7 9
* 				F:3 5 6 9
* 				G:4 7 8
* 				H:5 7 8 9
* 				I:6 8 9
* 				操作4次一个周期
* 				操作次数加上初始状态对4取余
* 	初始状态是：0,不用动,或者操作有4次的
* 			   1,3次。
* 			   2，2次。
* 			   3，1次。
* 	找到确定的(操作少的，A,C,G,I)：3个操作。0(不用操作)，1(3种操作必须全部),2(2),3(1)
* 	                    0,2,6,8
*/


#include <iostream>
using namespace std;

int oriClocks[9]; // 钟的原始状态
int clocks[9]; // 变化状态
			   // 九种移动方法对应操作的钟
			   // 指针指向常量
const char * moves[9] = { "ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI" };
int moveTimes[9] = { 0 }; // 移动次数，初始值全部是0
int result[9]; // 移动的结果，哪几种移动方案
int minTimes = 1 << 30; // 最小的次数初始值设置大

						// 枚举每一种可能
void Enum(int n) {
	// 如果n大于等于9
	if (n >= 9)
	{
		memcpy(clocks, oriClocks, sizeof(clocks)); // 把原始的数据拷贝到用于变化的数组中
		int totalTimes = 0; // 总共的次数
		for (int i = 0; i < 9; i++) { // 依次进行9次移动
			if (moveTimes[i]) { // 如果移动次数不是0
				for (int k = 0; moves[i][k] != NULL; k++) {
					// 开始移动,得到移动的结果
					clocks[moves[i][k] - 'A'] = (clocks[moves[i][k] - 'A'] + moveTimes[i]) % 4;
					totalTimes += moveTimes[i]; // 记录总的移动次数
				}
			}
		}
		// 查看是不是全部都是指向12点，全部都是0
		for (i = 0; i < 9; i++) {
			if (clocks[i]) {
				break;
			}
		}
		// 如果i等于9,说明全部始终都是12点
		if (i == 9) {
			// 判断移动次数
			if (minTimes > totalTimes) {
				minTimes = totalTimes;
				memcpy(result, moveTimes, sizeof(result));
			}
		}
		return; // 不管成不成功都退出函数
	}
	// 设置移动次数的所有可能性,移动0-3次是有意义的
	for (int i = 0; i < 4; ++i) {
		moveTimes[n] = i; // 移动的次数
		Enum(n + 1);
	}
	return;
}

/**
* moveTimes的数组下标代表着对应的操作种类
* 			  值代表使用该操作种类的次数，
			  操作次数0-3次是有意义的
*             012345678
* []moveTimes 000000000
*             000000001
*             000000002
*             000000003
*
* -------------枚举4^9次方种可能-------
*/

int main(int argc, char const *argv[])
{
	// 输入初始状态
	for (int i = 0; i < 9; ++i)
	{
		cin >> oriClocks[i];
	}
	Enum(0); //从A这个钟开始选择移动方案
	for (i = 0; i < 9; ++i) {
		for (int k = 0; k < result[i]; ++k) {
			cout << i + 1 << " ";
		}
	}
	return 0;
}
