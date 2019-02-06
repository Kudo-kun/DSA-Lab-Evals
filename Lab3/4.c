//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, u, v, cnt, queue[N], front, back;
/******************************************************************************/
void BFS(int init, int dest, int par[], int adj[][n])
{
    int visited[n], flag = 0;
    memset(visited, 0, n*sizeof(int));
    memset(par, -1, n*sizeof(int));
    front = 0; back = 0;
    visited[init] = 1;
    queue[back++] = init;

    while(front != back && !flag)
    {
        int x = queue[front++];
        for(int j = 0; j < n; j++)
            if(adj[x][j] && !visited[j])
            {
                visited[j]= 1;
                queue[back++] = j;
                par[j] = x;
                if(j == dest)
                    return;
            }
    }
}


int check(int dest, int par[])
{
    int flag = 0, last = dest;
    while(par[last] != -1)
    {
        if(last == v && !flag)
            flag = 1;
        else if(last == u && flag)
            return 0;
        
        last = par[last];
    }
    return 1;
}

/******************************************************************************/

int main()
{
    scanf("%d%d%d", &n, &u, &v);
    int adj[n][n];
    memset(adj, 0, n*n*sizeof(int));
    
    for(int i = 0, a, b; i < n-1; i++)
    {
        scanf("%d%d", &a, &b);
        a--; b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    u--; v--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j) 
            {  
                int par[n];
                BFS(i, j, par, adj);
                if(check(j, par))
                    cnt++;
            }
    
    printf("%d\n", cnt-1);
    return 0;
}
