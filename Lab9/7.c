#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 105
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int n, T, ans, flag, m;
int visited[N], mat[N][N];
/******************************************************************/
void DFS(int x, int dest, int k, int sum, int cnt)
{
	if(cnt > k)
		return;
	else if(x == dest)
		ans = min(ans, sum);
	else
		for(int j = 0; j < n; j++)
			if(mat[x][j])
				DFS(j, dest, k, (sum + mat[x][j]), cnt+1);
}
/******************************************************************/

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("outp.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for(int i = 0, u, v, cost; i < m; i++)
		scanf("%d%d%d", &u, &v, &cost), mat[u][v] = cost;

	scanf("%d", &T);
	while(T--)
	{
		int src, dest, k;
		ans = INT_MAX, flag = 0;
		scanf("%d%d%d", &src, &dest, &k);
		for(int j = 0; j < n; j++)
			if(mat[src][j])
				DFS(j, dest, k, mat[src][j], 0);

		(ans == INT_MAX) ? printf("-1\n") : printf("Minimum path cost is: %d\n", ans);
	}

	return 0;
}