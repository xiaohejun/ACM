#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
	1554: junlao的字符
*/




int main()
{
	//freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	string str;
	string strs[55];
	char ch;
	int n;
	for (int i = 0; i < t; ++i)
	{
		cin >> strs[i];
	}
	for (int i = 0; i < t; i++){
		str = strs[i];
		for (int i = 0; str[i] != '\0'; ++i) // 循环
		{
			if(str[i] >= '1' && str[i] <= '9'){
				n = str[i] - '0';
				for (int j = 0; j < n; ++j)
				{
					printf("%c", ch);
				}
			} else {
				ch = str[i];
				printf("%c", ch);
			}
		}
		printf("\n");
	}
	//fclose(stdin);
	return 0;
}



