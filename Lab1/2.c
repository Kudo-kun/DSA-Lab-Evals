//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n, cnt;
/******************************************************************************/
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void printMat(int mat[][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d\t", mat[i][j]);
        printf("\n\n\n\n");
    }
}


void BoundaryRing(int x, int y, int len, int mat[][n])
{
    for(int j = x; j < (x+len); j++)
        mat[y][j] = cnt--;
    for(int i = y+1; i < (y+len); i++)
        mat[i][x+len-1] = cnt--;
    for(int j = (x+len-2); j >= x; j--)
        mat[y+len-1][j] = cnt--;
    for(int i = (y+len-2); i > y; i--)
        mat[i][x] = cnt--;

    if(cnt)
        BoundaryRing(x+1, y+1, len-2, mat);
}


void Flip(int mat[][n])
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            if(!(i == j && i > n/2))
                swap(&mat[i][j], &mat[n-i-1][n-j-1]);

    printMat(mat);
}
/******************************************************************************/

int main()
{
    scanf("%d", &n); cnt = n*n;
    int mat[n][n];
    BoundaryRing(0, 0, n, mat);
    (n&1) ? Flip(mat) : printMat(mat);
    return 0;
}
