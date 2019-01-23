//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int n, m, minSum = INT_MAX;
/******************************************************************************/
int min(int a, int b)
{
	if(a <= b)
		return a;
	else
		return b;
}

int sumOfMat(int l, int r, int Acc[][n], int mat[][n])
{
	int sum = 0;
	for(int i = l; i < m+l; i++)
		sum += (Acc[i][m+r-1] - Acc[i][r] + mat[i][r]);

	return sum;
}


void printMat(int mat[][n])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", mat[i][j]);	
		printf("\n");
	}
}
/******************************************************************************/

int main()
{
	scanf("%d%d", &n, &m);
    int Acc[n][n], mat[n][n]; memset(Acc, 0, n*n*sizeof(int));

    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		scanf("%d", &mat[i][j]);

    for(int i = 0; i < n; i++)
    	for(int j = 0, sum = 0; j < n; j++)
    	{
    		sum += mat[i][j];
    		Acc[i][j] = sum;
    	}

    for(int i = 0; (i+m) < n; i++)
    	for(int j = 0; (j+m) < n; j++)
    	{
    		printf("%d %d\n", minSum, sumOfMat(i, j, Acc, mat));
    		minSum = min(minSum, sumOfMat(i, j, Acc, mat));
    	}
    
    printf("%d\n", minSum);
    printMat(Acc);
    return 0;
}
