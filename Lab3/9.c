//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 26
#define MAX 1005

int n, m, queue[N], front, back;
/******************************************************************************/
int filled(int arr[])
{
    for(int i = 0; i < n; i++)
        if(!arr[i])
            return 0;

    return 1;
}


void BFS(int visited[], int adj[][n])
{
    while(front != back)
    {
        int x = queue[front++];
        for(int j = 0; j < n; j++)
            if(adj[x][j] && !visited[j])
            {
                queue[back++] = j;
                visited[j] = 1;
            }
    }
}

/******************************************************************************/

int main()
{
    scanf("%d%d", &n, &m);
    int adj[n][n], visited[n];
    memset(adj, 0, n*n*sizeof(int));

    for(int i = 0, x, y; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        adj[x-1][y-1] = 1;
    }

    int ans[n], size = 0;
    for(int i = 0; i < n; i++)
    {
        memset(visited, 0, n*sizeof(int));
        front = 0; back = 0;
        queue[back++] = i;
        visited[i] = 1;
        BFS(visited, adj);
        if(filled(visited))
            ans[size++] = (i+1);
    }

    if(!size)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i = 0; i < size; i++)
            printf("%d ",ans[i]);
    }
    return 0;
}
