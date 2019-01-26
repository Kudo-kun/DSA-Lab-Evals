//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005

int e, v, queue[N], front, back, diameter;
/******************************************************************************/
void BFS(int init, int visited[], int dist[][v], int adj[][v])
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


void spec_BFS(int init, int fin, int visited[], int adj[][v])
{
	int par[v]; par[init] = -1;
	while(front != back)
	{
		int x = queue[front++];
		for(int j = 0; j < v; j++)
			if(adj[x][j] && !visited[j])
			{
				if(j == fin)
				{
					par[j] = x;
					printPath(fin, par);
				}
				else 
				{
					queue[back++] = j;
					par[j] = x;
					visited[j] = 1;
				}
			}
	}
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
		BFS(i, visited, dist, adj);
	}

	maxOfMat(dist);
	printf("Diameter of graph is: %d\n", diameter);

	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			if(dist[i][j] == diameter)
			{
				//dist[j][i] = -1;				
				memset(visited, 0, v*sizeof(int)); front = 0; back = 0;
				queue[back++] = i; visited[i] = 1;
				spec_BFS(i, j, visited, adj);
			}
    
	return 0;
}
