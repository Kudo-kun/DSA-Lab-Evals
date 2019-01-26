//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005


int e, v, queue[N], front, back, diameter, par[N];
/******************************************************************************/
void ShortestPaths(int init, int visited[], int dist[][v], int adj[][v])
{
	int len = 0;
	while((front != back) && ++len)
	{
		int x = queue[front++];
		for(int j = 0; j < v; j++)
			if(adj[x][j] && !visited[j])
			{
				visited[j] = 1; queue[back++] = j;
				dist[init][j] = len;
			}
	}
}


void maxOfMat(int mat[][v])
{
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			if(mat[i][j] > diameter)
				diameter = mat[i][j];
}


void printPath(int last, int par[])
{
	while(par[last] != -1)
	{
		printf("%d -> ", last);
		last = par[last];
		if(par[last] == -1)
			printf("%d\n", last);
	}
}


void spec_DFS(int x, int fin, int visited[], int adj[][v])
{
	if(x == fin)
	{
		int last = x, len = 0;
		while(par[last] != -1)
			{ len++; last = par[last];}	

		if(len == diameter)
			printPath(fin, par);
	}
	else if(!visited[x])
	{
		for(int j = 0; j < v; j++)
			if(adj[x][j] && !visited[j])
			{
				par[j] = x;
				visited[x] = 1;
				spec_DFS(j, fin, visited, adj);
			}
	}
	visited[x] = 0;
	return;
}
/******************************************************************************/

int main()
{
	scanf("%d%d", &v, &e);
	int adj[v][v], visited[v], dist[v][v];
	memset(dist, 0, v*v*sizeof(int));

	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			scanf("%d", &adj[i][j]);

	for(int i = 0; i < v; i++)
	{
		memset(visited, 0, v*sizeof(int)); 
		front = 0; back = 0;
		visited[i] = 1; queue[back++] = i;
		ShortestPaths(i, visited, dist, adj);
	}

	maxOfMat(dist);
	printf("Diameter of graph is: %d\n", diameter);

	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			if(dist[i][j] == diameter)
			{
				dist[j][i] = -1;
				memset(visited, 0, v*sizeof(int));
				memset(par, 0, N*sizeof(int));				
				par[i] = -1; visited[i] = 1;

				for(int x = 0; x < v; x++)
					if(adj[i][x])
					{
						par[x] = i;
						spec_DFS(x, j, visited, adj);
					}
			}
    
	return 0;
}