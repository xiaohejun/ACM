#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

/*
	1832: Classes(oj)

*/

//const int max_n = 1010;
int arr[8];

int main()
{
	freopen("in.txt", "r", stdin);
	int N,T;
	cin >> T;
	while(T--) {
	    int a = 0, b = 0;
	    int ans = 0;
	    bool is = false;
	    cin >> N;
	    for (int i = 0; i < N; ++i) 
	    {
	    	for (int j = 0; j < 7; ++j)
	    	{
	    		cin >> arr[j];
	    	}
	    	for (int j = 0; j < 7; ++j)
	    	{	
	    		
	    	}
	    	if(is) {
	    		//cout << "i=" << i << endl;
	    		for (int j = 0; j < 7; ++j)
	    		{	
	    			//cout << arr[j] << " ";
	    			ans += arr[j];
	    		}
	    		break;
	    	}
	    }
	    cout << ans << endl;
	}
	fclose(stdin);
	return 0;
}