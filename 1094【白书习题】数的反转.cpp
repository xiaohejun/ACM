#include "stdafx.h"
/*
1094: 【白书习题】数的反转
*/

#include <iostream>
using namespace std;

const int max_t = 20;
int n;
long long t;
char a[max_t];
long long result;

int main()
{	
	//freopen("in.txt", "r", stdin);
	cin >> n;
	int k = 0;
	int num;
	int i,j;
	while (n--)
	{
		cin >> t;
		while (t)
		{
			num = t % 10;
		//	cout << "num=" << num <<endl;
			a[k++] = num + '0';
			//cout << "a[k-1]=" << a[k-1] << endl;
			t /= 10;
		}
		//cout << "a[0]=" << a[0] << endl;
		if (k == 0) a[0] = '0';
		k++;
		for (i = 0; i < k - 1; i++) {
			if (a[i] != '0') break;
		}
		//cout << "i=" << i << endl;
		cout << a + i << endl;
		k = 0;
		//memset(a, 0, sizeof(a));
	}
	//fclose(stdin);
	return 0;
}
