#include "stdafx.h"
#include <iostream>
using namespace std;

long sum(n){
	if(n == 0){
		return 0;
	}
	return n+f(n-1);
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >>n){
		cout << n << endl;
	}
	return 0;
}