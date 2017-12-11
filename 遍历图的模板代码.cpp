

Dfs(V){
	if(V是旧的点)
		return ;
	将V标记成旧点
	对和V相邻的每个点U {
		Dfs(U);
	}
}

int main(int argc, char const *argv[])
{
	将所有点标记成新点;
	while(在图中找到新点k)
		Dfs(k);
	return 0;
}