//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105

int n, queue[N], front, back;
/******************************************************************************/
int BFS(int univ[], int visited[], int adj[][n])
{
	while(front != back)
	{
		int x = queue[front++];
		for(int j = 0; j < n; j++)
			if(adj[x][j] && !visited[j])
			{
				queue[back++] = j;
				visited[j] = 1;
				if(univ[j])
					return j;
			}
	}
	return -1;
}


/******************************************************************************/

int main()
{
	scanf("%d", &n);
	int adj[n][n], m, visited[n];
	memset(adj, 0, n*n*sizeof(int));
	memset(visited, 0, n*sizeof(int));

	for(int i = 0, v, u; i < n-1; i++)
	{
		scanf("%d%d", &u, &v);
		adj[u][v] = 1; adj[v][u] = 1;
	} 


	scanf("%d", &m);
	int univ[m]; 
	memset(univ, 0, m*sizeof(int));

	for(int i = 0, x; i < m; i++)
	{
		scanf("%d", &x);
		univ[--x] = 1;
	}


	visited[0] = 1; queue[back++] = 0;
	printf("Nearest city with a university is %d.\n", BFS(univ, visited, adj)+1);
	return 0;
}
