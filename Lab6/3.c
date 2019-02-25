//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105
#define ll long long int


int n, k, ans, visited[N];
/******************************************************************************/
void DFS(int x, int cnt, int cats[], int mat[][n])
{
	if(visited[x])
		return;

	int isLeaf = 0;
	if(cnt <= k && !cats[x])
		cnt = 0;
	else if(cnt <= k && cats[x])
		cnt++;
	for(int j = 0; j < n; j++)
		if(mat[x][j])
		{
			isLeaf++;
			visited[x] = 1;
			DFS(j, cnt, cats, mat);
		}
		
	if(cnt <= k && isLeaf == 1)
		ans++;
}
/******************************************************************************/

int main()
{
	scanf("%d%d", &n, &k);
	int mat[n][n], visited[n], cats[n];
	memset(mat, 0, n*n*sizeof(int));
	memset(visited, 0, n*sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", cats+i);
	for(int i = 0, a, b; i < (n-1); i++)
	{
		scanf("%d%d", &a, &b); 
		mat[a-1][b-1] = 1;
		mat[b-1][a-1] = 1;
	}

	for(int j = 0; j < n; j++)
		if(mat[0][j])
		{
			visited[0] = 1;
			(cats[0] == 1) ? DFS(j, 1, cats, mat) : DFS(j, 0, cats, mat);
		}
	
	printf("\nFinal answer is: %d\n", ans);
	return 0;
}
