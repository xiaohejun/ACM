#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
	1823: 阿纳斯塔西娅与鹅卵石
*/

const int max_n = 100010;
int arr[max_n]; // 数量

typedef long long L;

int main()
{
	//freopen("in.txt", "r", stdin);
	L n,k,ans=0;
	cin >> n >> k; // 输入n,k
	for (L i = 0; i < n; ++i) // 输入数据
	{
		cin >> arr[i];
	} 
	sort(arr,arr+n); // 从小到大排序
	int first = 0, second = 1;
	while(arr[n-1] > 0){ 
		arr[first] -= k;
		arr[second] -= k;
		ans++;
		if(arr[first] <= 0 && arr[second] > 0) {first = second; second = first+1;}
		if(arr[first] <= 0 && arr[second] <= 0) {first = second+1; second = first+1;}
		if(second >= n) {second=first;}
	}
	cout << ans << endl; 
	//fclose(stdin);
	return 0;
}



