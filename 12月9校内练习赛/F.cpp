/*
	这道题目按照题目描述模拟一下就好
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 15;
int N,M,S;
char ch[MAX_N][MAX_N]; // 地图所寸数据
bool has[MAX_N][MAX_N]; // 判断有没有走过
int steps[MAX_N][MAX_N]; // 在每一个点的步数


int d[4][2] = { // 四个方向走
	{1,0}, // S 0
	{-1,0}, // N 1
	{0,1}, // E 2
	{0,-1} // W 3
};


int cal(char c){ // 四个方向对应的数组下标
	switch(c){
		case 'S':return 0;
		case 'N':return 1;
		case 'E':return 2;
		case 'W':return 3;
	}
}

void solve(){
	memset(has, false, sizeof has); // 初始化全部是没有走过
	memset(steps, 0, sizeof steps); // 初始化在每一个点的步数是0
	bool hasloop = false; // 判断有没有圈
	int step = 0,loopstep = 0; // 没有圈的部分的步数,有圈部分的步数
	int x,y; // 坐标
	has[1][S] = true; // 一开始在的坐标是(1,S),(1,S)走过
	steps[1][S] = 1; // 在这个点的步数是1
	step = steps[1][S]; // 寸这个点的步数
	x = 1; y = S; // 一开始在的坐标是(1,S)
	int pos; // 当前位置的方向
	while(true) {
		pos = cal(ch[x][y]); // 得到方向
		x += d[pos][0]; // 即将走向的下一个方向
		y += d[pos][1];
		if(x < 1 || x > N || y < 1 || y > M) break; // 走出来了
		else step++; // 没有走出来.步数加1
		if(has[x][y]) { // 如果走过这个点.说明有圈
			hasloop = true; // 有圈
			loopstep = step - steps[x][y]; // 得到圈的步数
			step -= loopstep; // 得到没有圈的步数,减1之后是答案.自己带数字进去算就知道了
			step--;
			break;
		}
		else { // 没有访问过.就走向这个点
			has[x][y] = true; // 这个点走到了.记录成访问过
			steps[x][y] = step; // 存步数
		}
	}
	if(hasloop) printf("%d step(s) before a loop of %d step(s)\n", step,loopstep); // 输出答案
	else printf("%d step(s) to exit\n", step);
}

int main(){
	//freopen("in.txt", "r", stdin);
	while(cin >> N >> M >> S && N && M && S) {
	    for(int i = 1; i <= N; i++) scanf("%s", ch[i]+1); // 输入数据
	    solve();
	}
	return 0;
}