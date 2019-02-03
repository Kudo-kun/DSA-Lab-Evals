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
int BFS(int fin, int visited[], int adj[][n])
{
    while(front != back)
    {
        int x = queue[front++];
        for(int j = 0; j < n; j++)
            if(adj[x][j] && !visited[j])
            {
                queue[back++] = j;
                visited[j] = 1;
                if(j == fin)
                    return 1;
            }
    }
    return 0;
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

    int t; scanf("%d", &t);
    while(t--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        memset(visited, 0, n*sizeof(int)); 
        front = 0; back = 0;
        x--; y--;

        queue[back++] = x;
        (BFS(y, visited, adj)) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
