/*
著名的哥德巴赫猜想是：每个不小于6
的偶数都可以表示为两个奇素数之和。例如，１６＝３＋１
３＝５＋１１。下面需要你来编程验证一下哥德巴赫猜想是否正确。
*/
/*
你需要输出Ｎ行数据，每行以升序输出两个素数，这两个素数的和等于输入中的那个偶数，如果有
多种选择，输出乘积最大的，例如
Ｎ＝＝１６时，输出５
１１，而不是３
１３。
*/

/*
输入：6 16 20
输出：3 3
5 11
7 13

*/
#include<stdio.h>
#include<math.h>

// 判断是不是素数
int is_prime(int n) {
	// 拿一个数记录n的平方根
	int m = sqrt(n);
	int i;
	// 1不是素数,从2开始循环到到它的平方根
	for (i = 2; i <= m; i++) {
		// 如果n对i取余是0，说明它不是素数
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}



void main() {
	int n=6; // 定义n来接收输入的值
	while (n != EOF) {
		scanf("%d", &n);
		int m = n / 2; // 取n的一半
		if (m % 2 == 0)
		{
			--m; // 取一半并且确保是奇数，可以减少后面的循环次数
		}
		// 找符合的数
		while (1)
		{
			if (is_prime(m) && is_prime(n - m))
			{
				// 找到符合的数输出
				printf("%d %d\n", m, n - m);
				break;
			}
			else {
				m -= 2; // 奇数是素数的可能性比较大
			}
		}
	}
}
