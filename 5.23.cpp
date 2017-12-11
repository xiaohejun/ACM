#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 * 
 * 5.23
 */


#define Max 128 // 最多的行数
typedef int ElemType; // 数据类型

typedef struct
{
    int col; // 列数
    ElemType e; // 数据
}Two;

// 矩阵
class Matrix {
    private:
        Two *p; // 指向非零元的指针
        int rpos[Max]; // 每行第一个非零元在二元组中的序号
        int row; // 行数
        int col; // 列数
        int count; // 非零元个数
    public:
        Matrix(){} // 无参构造函数
        Matrix(int r, int c, int n); // 有参数构造函数
        void ShowElement(int i, int j); // 显示元素
};

// 初始化矩阵X
Matrix::Matrix(int r, int c, int n){
    row = r; col = c; count = n; // 分别赋值
    p = (Two *) malloc(sizeof(Two)*count+1); // 分配内存
    if(!p) return; // 指针没有分配成功
    // 输入数据
    int i ;
    for(i= 1; i <= count; i++){
        cout << "输入非零元的列标和值：" << endl;
        cin >> p[i].col >> p[i].e;
    }
    for(i = 1; i <= row; i++){
        cout << "输入每一行中第一个非零元的序号（没有输入-1）" << endl;
        cin >> rpos[i]; // 每行第一个非零元在二元组中的序号
    }
}

// 显示元素
void Matrix::ShowElement(int i, int j){
    if(i < 1 || i > row  || j < 1 || j > col) return; // 传入的参数范围不正确，不可能得到元素值
    ElemType x = 0; // 初始化成零元
    int s,d; // s记录该行第一个非零元在二元组的位置，d记录非零元的个数
    if(i == row){ // 如果是最后一行
        s = rpos[i];
        d = count;
    } else { // 不是最后一行
        s = rpos[i]; // 记录这一行第一个非零元在二元组的位置
        int m = 1;
        d = rpos[i+m]; // 找到下一行第一个非零元在二元组中的位置 
        while(d < 0){ // 说明要求的这一行的下一行没有非零元，都是零元
            if(i+m < row){
                m++;
                d = rpos[i+m];
            } else {
                d = count;
            }
        }
    }
    if(s > 0){ // 二元组的下标是从1开始的
        int k = s;
        while(k <= d){ // 开始找
            if(p[k].col == j){ // 找到列数相同
                x = p[k].e; // 赋值
            }
            k++;
        }
    }
    cout << x << endl;

}

int main(){
    //freopen("in.txt", "r", stdin);
    Matrix A(3,3,5); // 创造矩阵
    A.ShowElement(2,1); // 显示第2行，第1列下的元素
    //fclose(stdin);
    return 0;
}


/*
 * 运行结果：
 * 输入非零元的列标和值：
 * 1 1
 * 输入非零元的列标和值：
 * 2 2
 * 输入非零元的列标和值：
 * 3 3
 * 输入非零元的列标和值：
 * 1 4
 * 输入非零元的列标和值：
 * 3 5
 * 输入每一行中第一个非零元的序号（没有输入-1）
 * 1
 * 输入每一行中第一个非零元的序号（没有输入-1）
 * 4
 * 输入每一行中第一个非零元的序号（没有输入-1）
 * 9
 * 4
 */

