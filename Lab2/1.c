//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int e, v, cycle = INT_MAX;
/******************************************************************************/
int min(int a, int b)
{
	if(a <= b)
		return a;
	else 
		return b;
}


void DFS(int x, int sum, int visited[], int adj[v][v])
{
	if(visited[x])
		cycle = min(cycle, sum);
	else
	{
		for(int j = 0; j < v; j++)
			if(adj[x][j])
			{
				visited[x] = 1;
				DFS(j, (sum + adj[x][j]), visited, adj);
			}
	}

	visited[x] = 0;			//backtrack.
	return;
}
/******************************************************************************/

int main()
{
	scanf("%d%d", &v, &e);
	int adj[v][v], visited[v];
	memset(visited, 0, v*sizeof(int));
	
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			scanf("%d", &adj[i][j]);

	for(int i = 0; i < v; i++)
		for(int j = 0, cycle = 0; j < v; j++)
			if(adj[i][j])
			{
				visited[i] = 1;
				DFS(j, adj[i][j], visited, adj);
				visited[i] = 0;			//backtrack.
			}

    
    (cycle != INT_MAX) ? printf("\nMinmum weight cycle: %d\n", cycle) : printf("\nNo cycles are present!\n");
    return 0;
}
