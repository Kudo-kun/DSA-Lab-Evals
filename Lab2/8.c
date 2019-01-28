//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int n, t, count = 0;
/******************************************************************************/
void DFS(int init, int x, int dist, int visited[], int adj[][n])
{
	if(dist == (t+1))																
		count++; 
	
	else
		for(int j = 0; j < n; j++)
			if(adj[x][j] && !visited[j])
			{ 
				visited[x] = 1;
				DFS(init, j, (dist + 1), visited, adj); 
			}
	
	visited[x] = 0; 
	return;
}
/******************************************************************************/

int main()
{   
	scanf("%d", &n);
	int adj[n][n], visited[n];
	memset(adj, 0, n*n*sizeof(int));

	for(int i = 0, x, y; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		adj[x][y] = 1; 
		adj[y][x] = 1;
	}
	
	scanf("%d", &t);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(adj[i][j])
			{
				memset(visited, 0, n*sizeof(int));
				visited[i] = 1;
				DFS(i, j, 1, visited, adj);
			}

	printf("\nNumber of nodes which are %d units from each other are: %d\n", t, count);
    return 0;
}
