#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long

int n, visited[N][N], path_cnt = INT_MAX;
int x, y, x2, y2;
/***************************************************************************************************************************/
void FindPath(int u, int v, int path, int mat[][n])
{
	visited[u][v] = 1;
	if(u == x2 && v == y2)
	{
		path_cnt = min(path_cnt, path);
		return;
	}
	if(u > 0 && mat[u-1][v] && !visited[u-1][v])
		FindPath(u-1, v, path+1, mat);
	if(v < n-1 && mat[u][v+1] && !visited[u][v+1])
		FindPath(u, v+1, path+1, mat);
	if(v > 0 && mat[u][v-1] && !visited[u][v-1])
		FindPath(u, v-1, path+1, mat);
	if(u < n-1 && mat[u+1][v] && !visited[u+1][v])
		FindPath(u+1, v, path+1, mat);
}
/***************************************************************************************************************************/

int main()
{	
	scanf("%d\n", &n);
	int mat[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			char c1, c2;
			scanf("%c%c", &c1, &c2);
			if(c1 == 'S')
				x = i, y = j;
			if(c1 == 'H')
				x2 = i, y2 = j;
			mat[i][j] = ((c1 != 'B') ? 1 : 0);
		}

	FindPath(x, y, 0, mat);
	printf("%d\n", path_cnt);
	return 0;
}



       
       


