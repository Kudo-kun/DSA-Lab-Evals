//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105


int e, v, cnt = 1, flag = 0, queue[N], front, back, state;
/******************************************************************************/
void ReadMat(int G[][v])
{
	for(int i = 0; i < v; i++)
		for(int j = 0, t; j < v; j++)
		{
			scanf("%d", &t);
			if(t == 1 && j >= i && !G[j][i])
				{ G[i][j] = cnt++; G[j][i] = G[i][j]; }	
		}
}


void Complement(int x, int G[][v], int Gcomp[][e])
{
	for(int i = 0; i < v; i++)
		if(G[x][i])
			for(int j = i+1; j < v; j++)
				if(G[x][j])
				{ 
					Gcomp[G[x][i] - 1][G[x][j] - 1] = 1; 
					Gcomp[G[x][j] - 1][G[x][i] - 1] = 1;
				}
}


int countZeros(int arr[])
{
	int num = 0;
	for(int i = 0; i < e; i++)
		if(arr[i] == 1)
			num++;

	return (num == (e-1));
}


void printMat(int forb, int mat[][e])
{
	printf("Cut Vertex is %d, connected components are:\n", forb); flag = 1;
	for(int i = 0; i < e; i++)
	{
		for(int j = 0; j < e; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}

	printf("\n\n");
}


void BFS(int forb, int visited[], int Gcomp[][e])
{
	int mat[e][e];
	memset(mat, 0, e*e*sizeof(int));

	while(front != back)
	{
		int x = queue[front++]; visited[x] = 1;
		for(int j = 0; j < e; j++)
			if(j != forb && !visited[j] && Gcomp[x][j])
			{
				queue[back++] = j;
				mat[x][j] = 1; mat[j][x] = 1;
			}
	}

	if(!countZeros(visited))
		printMat(forb, mat);
} 
/******************************************************************************/

int main()
{
	scanf("%d%d", &v, &e);
	int G[v][v], Gcomp[e][e];
	memset(G, 0, v*v*sizeof(int));
	memset(Gcomp, 0, e*e*sizeof(int));
	
	ReadMat(G);
	for(int i = 0; i < v; i++)
		Complement(i, G, Gcomp);
	
	printf("\n\n");
	for(int i = 0; i < e; i++)
	{
		//!i denotes the starting vertex(0 when i > 0, and 1 when i = 0)
		//i denotes the forbidden vertex;
		state = 0;
		int visited[e]; memset(visited, 0, e*sizeof(int));
		visited[i] = -1;
	
		for(int j = !i; j < e; j++)
			if(!visited[j])
			{
				front = 0; back = 0;
				queue[back++] = j; visited[j] = 1;
				BFS(i, visited, Gcomp);
			}
	}

	if(!flag) 
		printf("No such nodes!\n");
	
	return 0;
}

