/******************
 *
 *  6.42
 *
 ******************/

#include <cstdio>
#include <iostream>

using namespace std;


// 状态码
typedef char TElemType;

typedef struct BiTNode{
    TElemType data; // 数据
    struct BiTNode *lchild, *rchild; // 左右孩子指针
}BiTNode, *BiTree;

//-----------------二插树的基本操作函数---------------
// 创建二叉树
// 按先序次序输入二插树结点的值(字符)，#字符表示空树
void CreateBiTree(BiTree &T){
    TElemType c;
    cin >> c;
    if(c == '#') T = NULL;
    else {
        T = new BiTNode;
        T->data = c;
        CreateBiTree(T->lchild); // 创建左子树
        CreateBiTree(T->rchild); // 创建右子树
    }
}

//前序遍历二叉树并打印出来
void Preorder(BiTree T)
{
    if(T)
    {
        cout<<T->data<<" ";
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}

// 计算叶子节点的数目
int CountLeafNodeNum(BiTree T){
    if(T){ // 不是空
        if(!T->lchild && !T->rchild){ // 左右结点都是空
            return 1;
        } 
        else {
            return CountLeafNodeNum(T->rchild)+CountLeafNodeNum(T->lchild); // 左右子树分别计算叶子结点
        }
    }
    return 0;
}


int main()
{   
    freopen("in.txt", "r", stdin);
    BiTree T;
    cout << "输入二叉树：" << endl;
    CreateBiTree(T); // 创建二叉树
    Preorder(T);
    cout << "该二叉树的叶子结点数是：" << CountLeafNodeNum(T) << endl;
    fclose(stdin);
    return 0;
}

/*
输入二叉树：abcd###e##fhi###j##
a b c d e f h i j 该二叉树的叶子结点数是：4
*/
