//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 1000

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


void SieveOfErato(int arr[])
{
    int tmp[N], m = 0;
    memset(tmp, 0, N*sizeof(int));
    for(int i = 2; i <= sqrt(N); i++)
        for(int j = 2; i*j <= N; j++)
            tmp[i*j] = 1;

    for(int i = 1; i < N && m <= cnt; i++)
        if(!tmp[i])
            arr[m++] = i;
}


void BoundaryRing(int x, int y, int len, int arr[], int mat[][n])
{
    for(int j = x; j < (x+len); j++)
        mat[y][j] = arr[cnt--];
    for(int i = y+1; i < (y+len); i++)
        mat[i][x+len-1] = arr[cnt--];
    for(int j = (x+len-2); j >= x; j--)
        mat[y+len-1][j] = arr[cnt--];
    for(int i = (y+len-2); i > y; i--)
        mat[i][x] = arr[cnt--];

    if(cnt)
        BoundaryRing(x+1, y+1, len-2, arr, mat);
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
    int mat[n][n], arr[n*n];
    SieveOfErato(arr);
    BoundaryRing(0, 0, n, arr, mat);
    (n&1) ? Flip(mat) : printMat(mat);
    return 0;
}
