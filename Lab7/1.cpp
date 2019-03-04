//Author: Kudo_kun
//813C
#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long int


const int N = 2e5+5;
vector<int> gp[N];
int n, k, dist1[N], dist2[N], visited[N], ans;


void DFS(int x, int dist[], int d)
{
    visited[x] = 1;
    dist[x] = d;
    for(auto it : gp[x])
        if(!visited[it])
            DFS(it, dist, d+1);
}



int main()
{
    cin >> n >> k;
    for(int i = 1, a, b; i < n; i++)
    {
        cin >> a >> b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }


    DFS(1, dist1, 0);
    memset(visited, 0, N*sizeof(int));
    DFS(k, dist2, 0);
    for(int i = 1; i <= n; i++)
        if(dist1[i] > dist2[i])
            ans = max(ans, 2*dist1[i]);

    cout << ans << endl;
    return 0;
}