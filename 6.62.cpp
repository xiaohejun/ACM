#include <stdio.h>
#include <malloc.h>


typedef struct CSNode // 孩子-兄弟结点的定义
{
	char data; // 数据
	struct CSNode *firstChild; // 孩子
	struct CSNode *nextSibling; // 兄弟
}CSNode, *CSTree;

int max(int a, int b){
	return a>b?a:b;
}


void createCSTree(CSTree &tree){ // 创建孩子-兄弟二叉树
	char c = getchar(); // 得到数据
	if(c == '*') tree = NULL; // 设置结束标志
	else{
		tree = (CSTree)malloc(sizeof(CSNode)); // 开辟一个结点
		tree->data = c; // 数据赋值
		createCSTree(tree->firstChild); // 孩子的递归定义
		createCSTree(tree->nextSibling); // 兄弟的递归定义
	}
}


int depthCSTree(CSTree T){ // 求孩子兄弟表示法树的深度
	int maxd=0,d=0;
	CSTree p; // 工作指针
	if(!T) return 0; // 空树
	else{
		for (d = 0,p=T->firstChild; p; p = p->nextSibling)
		{	
			d = depthCSTree(p); // 递归求
			maxd = max(maxd,d); // 更新maxd
		}
	}
	return maxd+1;
}


int main(int argc, char const *argv[])
{
	CSTree tree;
	printf("输入孩子-兄弟表示法的树\n");
	createCSTree(tree);
	printf("树的深度: %d\n", depthCSTree(tree));
	return 0;
}


