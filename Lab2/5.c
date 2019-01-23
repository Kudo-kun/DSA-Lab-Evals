//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50


int v, del, queue[N], front, back, cnt;
/******************************************************************************/
void printMat(int n, int mat[][n])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	printf("\n\n");
}


void BFS(int visited[], int adj[][v])
{
	int mat[v][v];
	memset(mat, 0, v*v*sizeof(int));

	while(front != back)
	{
		int x = queue[front++]; visited[x] = 1;
		for(int j = 0; j < v; j++)
			if(adj[x][j] && !visited[j])
			{
				queue[back++] = j; 
				mat[x][j] = 1;
				mat[j][x] = 1;
			}
	}
	printf("Connected component %d is:\n", ++cnt);
	printMat(v, mat);
}




/******************************************************************************/

int main()
{
	scanf("%d%d", &v, &del);
	int f[v+1], adj[v][v], visited[v];
	memset(adj, 0, v*v*sizeof(int));
	memset(visited, 0, v*sizeof(int));

	for(int i = 0, j, val; i < v; i++)
	{
		scanf("%d%d", &j, &val);
		f[j-1] = val;
	}

	for(int i = 0; i < v; i++)
		for(int j = i; j < v; j++)
			if(abs(f[i] - f[j]) >= del)
			{
				adj[i][j] = 1;
				adj[j][i] = 1;
			}

	printf("Main graph is:\n"); printMat(v, adj);
	
	for(int i = 0; i < v; i++)
		if(!visited[i])
		{
			front = 0; back = 0;
			queue[back++] = i; visited[i] = 1;
			BFS(visited, adj);
		}

	return 0;
}
