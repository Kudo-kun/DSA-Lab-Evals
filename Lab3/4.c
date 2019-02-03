//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 26
#define MAX 1005
#define ll long long int

int n, queue[N], front, back, x, y, ans;
/******************************************************************************/
void BFS(int init, int visited[], int adj[][n])
{
    int flag = 0;
    while(front != back)
    {
        int curr = queue[front++];
        if(curr == x)
            flag = 1;

        for(int j = 0; j < n; j++)
            if(adj[curr][j] && !visited[j])
            {
                if(j == y && flag == 1)
                    ans++;

                visited[j] = 1;
                queue[back++] = j;
            }
    }
    return;
}
/******************************************************************************/

int main()
{
    scanf("%d%d%d", &n, &x, &y);
    int adj[n][n], visited[n];
    memset(adj, 0, n*n*sizeof(int));
    for(int i = 0, a, b; i < n-1; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a-1][b-1] = 1;
        adj[b-1][a-1] = 1;
    }

    x--; y--;
    for(int i = 0; i < n; i++)
    {
        memset(visited, 0, n*sizeof(int));
        front = 0; back = 0;
        visited[i] = 1;
        queue[back++] = i;
        BFS(i, visited, adj);
    }
    
    printf("%d\n", ((n+1)*n)/2 - ans);
    return 0;
}
