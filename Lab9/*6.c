#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 105
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n, ans;
int arr[N], cnt;
/******************************************************************/
void getMinPath(int x, int y, int grid[][n])
{
	int prev = 0;
	while(x != (n-1) || y != (n-1))
	{
		if(((x < (n-1)) && (y < (n-1)) && (grid[x+1][y] < grid[x][y+1])) || y >= (n-1))
		{
			if(prev < grid[x+1][y])
				ans += (grid[x+1][y] - prev), prev = grid[x+1][y];
			x++;
		}
		else if(((x < (n-1)) && (y < (n-1)) && (grid[x+1][y] >= grid[x][y+1])) || x >= (n-1))
		{
			if(prev < grid[x][y+1])
				ans += (grid[x][y+1] - prev), prev = grid[x][y+1];
			y++;
		}
	}
}

/******************************************************************/

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("outp.txt", "w", stdout);

	scanf("%d", &n);
	int grid[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);
	
	getMinPath(0, 0, grid);
	printf("Min time is: %d\n", ans);
	return 0;
}