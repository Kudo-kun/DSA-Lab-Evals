//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long int
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int n, ans;
/******************************************************************************/
int check(int x, int y, int l, int b, int mat[][n])
{
	int sum = 0;
	for(int i = x; i <= (x+l); i++)
		for(int j = y; j <= (y+b); j++)
			sum += mat[i][j];

	return (sum == 1);
}
/******************************************************************************/

int main()
{
	// freopen("inp.txt", "r", stdin);
	// freopen("outp.txt", "w", stdout);
	
	scanf("%d", &n);
	int mat[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int l = 0; (l+i) < n; l++)
				for(int b = 0; (b+j) < n; b++)
					if(check(i, j, l, b, mat))
						ans++;

			

	printf("No. of submatrices with a single 1 in them are: %d\n", ans);
	return 0;
}


