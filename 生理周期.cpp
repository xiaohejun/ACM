/*
 * 生理周期:体力 23天 p
 * 			情商 28天 e
 * 			智商 33 天 i
 * 一个指定日子d,在d之后，下一次三个高峰落在同一天的日子
 */
#include <iostream>
#include <cstdio>
using namespace std;
#define N 21252

int main(int argc, char const *argv[])
{
	int p,e,i,d,caseNo = 0; // 定义变量，caseNo用于记录情况
	while(cin>> p>> e>>i>>d && p != -1) // p为-1时退出
	{	
		++caseNo; // 情况增加
		int k; // 下一次三高峰出现的天数
		for (k = d+1; (k-p)%23 ; ++k); // 循环退出找到下一次体力高峰的天数
		for (; (k-e)%28 ; k+=23); // 循环退出找到下一次体力,情商双高峰的天数
		for (; (k-i)%33 ; k+=23*28); // 循环退出找到下一次体力,情商,智商三高峰的天数
		cout<<"Case:"<<caseNo<<":the next triple peak occurs in "<<k-d<<" days"<<endl;
	}
	return 0;
}