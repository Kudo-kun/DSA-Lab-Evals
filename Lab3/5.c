//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 26
#define MAX 1005
#define ll long long int

int n, ans, cnt;
/******************************************************************************/
int max(int a, int b)
{
    if(a >= b)
        return a;
    else 
        return b;
}


void Count(int x, int y, int mat[][n], int visited[][n])
{
    if(mat[x-1][y] && !visited[x-1][y] && (x-1 >= 0))
    {
        visited[x-1][y] = 1;;
        ++cnt; Count(x-1, y, mat, visited);
    }
    if(mat[x-1][y+1] && !visited[x-1][y+1] && (x-1 >= 0) && (y+1 < n))
    {
        visited[x-1][y+1] = 1;
        ++cnt; Count(x-1, y+1, mat, visited);
    }
    if(mat[x][y+1] && (y+1 < n) && !visited[x][y+1])
    {
        visited[x][y+1] = 1;
        ++cnt; Count(x, y+1, mat, visited);
    }
    if(mat[x+1][y+1] && (x+1 < n) && (y+1 < n) && !visited[x+1][y+1])
    {
        visited[x+1][y+1] = 1;
        ++cnt; Count(x+1, y+1, mat, visited);
    }
    if(mat[x+1][y] && (x+1 < n) && !visited[x+1][y])
    {
        visited[x+1][y] = 1;
        ++cnt; Count(x+1, y, mat, visited);
    }
    if(mat[x+1][y-1] && (x+1 < n) && (y-1 >= 0) && !visited[x+1][y-1])
    {
        visited[x+1][y-1] = 1;
        ++cnt; Count(x+1, y-1, mat, visited);
    }
    if(mat[x][y-1] && (y-1 >= 0) && !visited[x][y-1])
    {
        visited[x][y-1] = 1;
        ++cnt; Count(x, y-1, mat, visited);
    }
    if(mat[x-1][y-1] && (x-1 >= 0) && (y-1 >= 0) && !visited[x-1][y-1])
    {
        visited[x-1][y-1] = 1;
        ++cnt; Count(x-1, y-1, mat, visited);
    }
    return;
}


/******************************************************************************/

int main()
{
    scanf("%d", &n);
    int mat[n][n], visited[n][n];
    memset(visited, 0, n*n*sizeof(int));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] && !visited[i][j])
            {
                cnt = 1;
                visited[i][j] = 1;
                Count(i, j, mat, visited);
                ans = max(ans, cnt);
            }
    
    printf("%d\n", ans);
    return 0;
}
