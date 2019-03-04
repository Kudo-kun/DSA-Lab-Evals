//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long long int
#define N 50
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int mat[N][N], dist[N][N], dist_new[N][N], visited[N];
int n, m, s, t, ans;
int front, back, queue[N];
/******************************************************************************/
void BFS(int src, int d[][N])
{
	front = back = 0;
	memset(visited, 0, N*sizeof(int));
	queue[back++] = src;
	visited[src] = 1;
	
	while(front != back)
	{
		int x = queue[front++];
		for(int j = 0; j < n; j++)
			if(!visited[j] && mat[x][j] && !d[j][src])
			{
				queue[back++] = j;
				visited[j] = 1;
				d[src][j] = d[j][src]= (d[src][x] + 1);
			}
	}
}
/******************************************************************************/

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	s--; t--;
	for(int i = 0, u, v; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		u--; v--;
		mat[u][v] = mat[v][u] = 1;
	}

	for(int i = 0; i < n; i++)
		BFS(i, dist);

	mat[s][t] = mat[t][s] = 1;
	for(int i = 0; i < n; i++)
		BFS(i, dist_new);


	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(dist[i][j] > dist_new[i][j] && !((i == s && j == t) || (i == t && j == s)))
				ans++;

	printf("\n%d\n", ans/2);
	return 0;
}


