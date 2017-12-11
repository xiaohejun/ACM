/*************************************************************************
	> File Name: 生日蛋糕.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月30日 星期一 19时11分14秒
 ************************************************************************/

#include <iostream>  
#include <cstdio>
#include <cstring>

using namespace std;  

char map[25][25];
int w,h,ans;

struct pos
{
	int x,y;
};

// 从点i,j开始走
void dfs(int i, int j){
    if(i < 0 || i >= h || j < 0 || j >= w || map[i][j] == '#') return ;
	ans++;
	map[i][j] = '#';
    dfs(i+1, j); // 下
	dfs(i-1, j); // 上
	dfs(i, j+1); // 右
	dfs(i, j-1); // 左
	return ;
}

int main()  
{   
    freopen("in.txt", "r", stdin);
    pos p;
    while(~scanf("%d%d", &w, &h) && w && h) {
    	ans = 0;
	    for (int i = 0; i < h; ++i)
	    {
	    	for (int j = 0; j < w; ++j)
	    	{	
	    		cin >> map[i][j];
	    		if(map[i][j] == '@') {p.x = i; p.y = j;}
	    	}
	    }
	    dfs(p.x, p.y);
	    printf("%d\n", ans);
    }
    fclose(stdin);
    return 0;  
}