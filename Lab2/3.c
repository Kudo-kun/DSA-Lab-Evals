//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int v, e, queue[N], front, back;
/******************************************************************************/
int BFS(int colors[], int adj[][v])
{
	while(front != back)
	{
		int x = queue[front++];		//x is the parent node for the rest of the nodes;
		for(int j = 0; j < v; j++)
			if(adj[x][j])
			{
				if((colors[j] == colors[x]) && colors[j] != -1)
					return 0;
				else if(colors[j] == -1)
				{
					colors[j] = (colors[x] ^ 1); 
					queue[back++] = j;
				}
			}
	}
	return 1;
}
/******************************************************************************/

int main()
{
	scanf("%d%d", &v, &e);
	int adj[v][v], colors[v];
	memset(colors, -1, v*sizeof(int));
	
	for(int i = 0; i < v; i++)
		for(int j = 0; j < v; j++)
			scanf("%d", &adj[i][j]);

	queue[back++] = 0; colors[0] = 1; 
	(BFS(colors, adj)) ? printf("Yes, it's a bipartite!\n") : printf("No, it's not a bipartite!");
	return 0;
}
