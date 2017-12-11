#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

/*
	1553: 宁神的沉思
*/

struct move
{
	char dir; // 方向
	int x; // 横坐标
	int y; // 总坐标
	move(){}
	move(char c, int i, int j){
		dir = c; x = i; y = j;
	}
};

const int max_n = 105;
int map[max_n][max_n];
struct move moveTo[4] = {{'N',-1,0},{'W',0,-1},{'S',1,0},{'E',0,1}}; // 四个方向

int main()
{      
	//freopen("in.txt", "r", stdin);
	int m,n;
	int x,y,k,l;
	char s;
	struct move pos;
	while(cin >> m >> n){
		if(m <= 3 || n <= 3) break;
		bool flag = true;
		for (int i = 0; i < m; ++i) // 输入数据
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j];
			}		
		}
		cin >> x >> y >> s >> k;
		for (l = 0; l < 4; ++l)
		{
			if(s == moveTo[l].dir) {
				pos = moveTo[l];
				break;
			} 
		}
		// 解决问题
		for (int i = 1; i <= k; ++i) // 走k步
		{	
			if(map[x][y] == 0) { // 这个地方没草
				l = (l+1)%4;
				pos = moveTo[l]; // 左转90度
				map[x][y] = 1; // 长草
				x += pos.x; y += pos.y; // 走一步
			} else {
				l = (l+3)%4;
				pos = moveTo[l]; // 右转90度
				map[x][y] = 0; // 没草
				x += pos.x; y += pos.y; // 走一步
			}
			if (x < 0 || x >= m || y < 0 || y >= n)
			{	
				flag = false;
				break;
			}
		}
		if(flag) cout << x << " " << y << endl;
		else cout << "Let us prepare a suit-dress for god Ning." << endl;
	}
	//fclose(stdin);
	return 0;
}

