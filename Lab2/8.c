//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int n, t, count;
/******************************************************************************/
void DFS(int x, int dist, int visited[], int adj[][n])
{
	if(!visited[x])
	{
		if(dist == t) 
			count++;
		
		else
			for(int j = 0; j < n; j++)
				if(adj[x][j])
				{ 
					visited[x] = 1;
					DFS(j, dist+1, visited, adj); 
				}
	}
	visited[x] = 0; 
	return;
}

/******************************************************************************/

int main()
{   
	scanf("%d", &n);
	int adj[n][n], visited[n];
	memset(visited, 0, n*sizeof(int));

	for(int i = 0, x, y; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		adj[x][y] = 1; adj[y][x] = 1;
	}

	scanf("%d", &t);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(adj[i][j])
			{
				visited[i] = 1;
				DFS(j, 1, visited, adj);
				visited[i] = 0;
			}

	printf("\nNumber of nodes at 't' distance from each other are: %d\n", (count >> 1));
    return 0;
}
