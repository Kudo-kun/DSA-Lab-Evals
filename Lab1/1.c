//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int n, flag = 0;
/******************************************************************************/
int min(int x, int* size, int pos[], int mat[][n])
{
    int minVal = INT_MAX; (*size) = 0;
    for(int j = 0; j < n; j++)
        if(mat[x][j] < minVal)
            minVal = mat[x][j];

    for(int j = 0; j < n; j++)
        if(mat[x][j] == minVal)
            pos[(*size)++] = j;

    return minVal;
}


int isSaddlePoint(int maxVal, int y, int mat[][n])
{
    for(int i = 0; i < n; i++)
        if(mat[i][y] > maxVal)
            return 0;

    flag = 1; return 1;
}
/******************************************************************************/

int main()
{
    scanf("%d", &n);
    int mat[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for(int i = 0; i < n; i++)
    {
        int pos[n], size, rowMin = min(i, &size, pos, mat);
        for(int j = 0; j < size; j++)
            if(isSaddlePoint(rowMin, pos[j], mat))
                printf("%d, %d\n", i+1, j+1);
    }

    if(!flag) printf("NO SADDLE POINTS!\n");
    return 0;
}
