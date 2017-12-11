/*
 * 输入
 * 一个整数N
 * 输出
 * 每行输出一个完美立方。输出格式为：
 * Cube = a, Triple = (b,c,d);
 */
/*
 * 输入
 * 一个整数N
 * 输出
 * 每行输出一个完美立方。输出格式为：
 * Cube = a, Triple = (b,c,d);
 */
#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[])
{	
	int N; // 正整数N
	scanf("%d", &N); // 输入正整数N
	for (int a = 2; a <= N; ++a) // a=[2,N]
	{	
		for (int b = 2; b < a; ++b) // b=[2,a-1]
		{
			for (int c = b; c < a; ++c) // c=[b,a-1]
			{
				for (int d = c; d < a; ++d) // d=[c,a-1]
				{
					if ((a*a*a) == (b*b*b + c*c*c + d*d*d))
					{	
						printf("Cube=%d,Triple=(%d,%d,%d)\n", a,b,c,d); // 输出
					}
				}
			}
		}
	}
	return 0;
}
/* 运行结果
24
Cube=6,Triple=(3,4,5)
Cube=12,Triple=(6,8,10)
Cube=18,Triple=(2,12,16)
Cube=18,Triple=(9,12,15)
Cube=19,Triple=(3,10,18)
Cube=20,Triple=(7,14,17)
Cube=24,Triple=(12,16,20)
*/