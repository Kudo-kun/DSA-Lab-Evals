//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long long int
#define N 50
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n, m, arr[N], adj[N][N], visited[N], Paths[N][N];
int queue[N], front, back;
int ans = INT_MAX, ans_cnt;
/******************************************************************************/
int shortestPaths(int init)
{
	front = back = 0;
	memset(visited, 0, N*sizeof(int));
	queue[back++] = init;
	visited[init] = 1;
	Paths[init][init] = 1;
	while(front != back)
	{
		int x = queue[front++];
		for(int j = 0; j < n; j++)
			if(!visited[j] && adj[x][j])
			{
				queue[back++] = j;
				visited[j] = 1;
				Paths[init][j] = 1;
			}
	}
}


int check()
{
	for(int i = 0; i < n; i++)
		if(!visited[i])
			return 0;
	
	return 1;
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);
	for(int i = 0, x, y; i < m; i++)
		scanf("%d%d", &x, &y), adj[x-1][y-1] = 1;
	for(int i = 0; i < n; i++)
		shortestPaths(i);
	for(int i = 0, sum; i < (1 << n); i++)
	{
		sum = 0, memset(visited, 0, N*sizeof(int));
		for(int j = (1 << (n-1)), k = n-1; j > 0; j >>= 1, k--)
			if(i & j)
			{
				sum += arr[k];
				for(int x = 0; x < n; x++)
					if(Paths[k][x] && Paths[x][k])
						visited[x] = 1;
			}

		if(check() && sum < ans)
			ans_cnt = 1, ans = sum;
		else if(check() && sum == ans)
			ans_cnt++;
	}

	printf("%d %d\n", ans, ans_cnt);
	return 0;
}


