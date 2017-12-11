#include <stdio.h>


#define N 21252

int main()
{	
	freopen("4148.txt", "r", stdin);
	int p,e,i,d,caseNo = 0; // 定义变量，caseNo用于记录情况
	while(~scanf("%d%d%d%d", &p, &e, &i, &d) && p != -1) // p为-1时退出
	{	
		int k; // 下一次三高峰出现的天数
		for (k = d+1; (k-p)%23 ; ++k); // 循环退出找到下一次体力高峰的天数
		for (; (k-e)%28 ; k+=23); // 循环退出找到下一次体力,情商双高峰的天数
		for (; (k-i)%33 ; k+=23*28); // 循环退出找到下一次体力,情商,智商三高峰的天数
		printf("Case %d: the next triple peak occurs in %d days.\n", ++caseNo, k-d);
	}
	return 0;
}