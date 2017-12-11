

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// 输入并且计算逆波兰表达式
double exp(){
	char c[20];
	cin >> c;
	switch(c[0]){
		case '+': return exp()+exp();
		case '-': return exp()-exp();
		case '*': return exp()*exp();
		case '/': return exp()/exp();
		default: return atof(c);break;
	}
}

int main(int argc, char const *argv[])
{
	printf("%lf\n", exp());
	return 0;
}





