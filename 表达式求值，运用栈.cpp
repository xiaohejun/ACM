#include <stack>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
    表达式求值，运用栈 
*/

char OP[] = "+-*/()#"; // 运算符
char Re[8][8] = { // 运算符优先权表
    {'>','>','<','<','<','>','>'},
    {'>','>','<','<','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'<','<','<','<','<','=',' '},
    {'>','>','>','>',' ','>','>'},
    {'<','<','<','<','<',' ','='}
};

typedef int OperandType; // 表达式数据类型

// 判断是不是运算符
bool In(char c,char *ch, int len){
    int i;
    for (i = 0; i < len; ++i)
    {
        if(ch[i] == c) break;
    }
    return i < len;
}

// 比较优先级
char Precede(char a, char b){
    int i,j;
    for (i = 0; i < strlen(OP); ++i)
    {
        if(a == OP[i]) break;
    }
    for (j = 0; j < strlen(OP); ++j)
    {
        if(a == OP[j]) break;
    }
    return Re[i][j];
}

// 计算
OperandType Operate(OperandType a,char theta,OperandType b) {
    switch(theta){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

// 计算表达式
OperandType EvaluateExpression(){
    stack<OperandType> OPND; // 运算数字
    stack<char> OPTR; // 运算符
    OPTR.push('#'); // 开头和结尾用#表示
    OperandType num; // 数字
    char c = cin.peek();
    while(c != '#' || OPTR.top() != '#'){ // 表达式没有结束
        if(!In(c,OP,strlen(OP))) { cin >> num; OPND.push(num); } // 不是运算符就进数字的栈
        else { // 是运算符，比较优先级
            cin.get();
            switch(Precede(OPTR.top(),c)) {
                case '<': // 栈顶元素优先权低
                    OPTR.push(c); c = cin.peek();
                    break;
                case '=':
                    OPTR.pop(); c = cin.peek();
                    break;
                case '>':
                    char theta = OPTR.top();
                    OPTR.pop();
                    OperandType a = OPND.top();
                    OPND.pop();
                    OperandType b = OPND.top();
                    OPND.pop();
                    OPND.push(Operate(a,theta,b));
                    break; 
            }
        }
    }
    return OPND.top(); // 返回结果
}

int main()
{
    freopen("in.txt", "r", stdin);
    cout << EvaluateExpression() << endl;
    fclose(stdin);
    return 0;
}
