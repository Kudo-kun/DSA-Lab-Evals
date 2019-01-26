//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005


int e, v, cycle = INT_MAX, queue[N], front, back;
/******************************************************************************/
int min(int a, int b)
{
    if(a <= b)
        return a;
    else
        return b;
}


void PrintArr(int n, int arr[])
{
    for(int i = n-1; i >=0; i--)
        printf(" %d ->", arr[i]);
    
    printf(" %d\n", arr[n-1]);
}


void ShortestPaths(int init, int visited[], int weights[][v], int adj[][v])
{
    while(front != back)
    {
        int x = queue[front++];
        for(int j = 0; j < v; j++)
            if(adj[x][j] && !visited[j])
            {
                queue[back++] = j;
                weights[init][j] = weights[init][x] + adj[x][j];
                visited[j] = 1;
            }
    }
}


void GetMinWeightCycle(int weights[][v])
{
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            if(weights[i][j] && weights[j][i])
                cycle = min(cycle, (weights[i][j] + weights[j][i]));
}


void spec_BFS(int init, int fin, int* len, int path[], int adj[][v])
{
    int par[N], visited[v], flag = 0;
    par[init] = -1; front = 0; back = 0;
    queue[front++] = init;
    memset(visited, 0, v*sizeof(int));
    visited[init] = 1;

    while((front != back) && !flag)
    {
        int x = queue[back++];
        for(int j = 0; j < v; j++)
            if(adj[x][j] && !visited[j])
            {
                par[j] = x;
                queue[front++] = j;
                visited[j] = 1;
                if(j == fin)
                    {flag = 1; break;}
            }
    }

    int last = fin;
    while(par[last] != -1)
    {
        path[(*len)++] = last;
        last = par[last];
    }
}


/******************************************************************************/
 
int main()
{
    scanf("%d%d", &v, &e);
    int adj[v][v], weights[v][v], visited[v], init, fin;
    memset(weights, 0, v*v*sizeof(int));

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            scanf("%d", &adj[i][j]);


    for(int i = 0; i < v; i++)
    {
        memset(visited, 0, v*sizeof(int)); front = 0; back = 0;
        queue[back++] = i; 
        visited[i] = 1;
        ShortestPaths(i, visited, weights, adj);
    }

    
    GetMinWeightCycle(weights);
    printf("\nMinimum cycle weight is: %d\n", cycle);
    
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            if((weights[i][j] + weights[j][i]) == cycle)
            {
                int path[N], len = 0; 
                spec_BFS(i, j, &len, path, adj);
                spec_BFS(j, i, &len, path, adj); 
                PrintArr(len, path); 
                weights[j][i] = 0;
            }

    return 0;
}