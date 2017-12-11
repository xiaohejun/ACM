#include <bits/stdc++.h>

using namespace std;

int main(){
	//freopen("in.txt", "r", stdin);
	int n;
	float money = 0.0;
	float num;
	while(cin >> n) {
	    money = 0.0;	
	    for (int i = 0; i < n; ++i)
	    {
	    	cin >> num;
	    	if(num <= 70) money += 0.1;
	    	else money += ceil(num/70)*0.1;
	    }
	    printf("%.1f\n", money);
	}
	return 0;
}