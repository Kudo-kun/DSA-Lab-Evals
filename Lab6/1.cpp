//Author: Kudo_kun
//500B
#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long int

const int N = 310;
int n, visited[N], mat[N][N];
vector<int> gp[N], aux, pos;
string tmp;

void DFS(int x, int a[])
{
    visited[x] = 1;
    pos.push_back(x);
    aux.push_back(a[x]);
    for(int j = 1; j <= n; j++)
        if(!visited[j] && mat[x][j])
            DFS(j, a);
}


void func(int a[])
{
    sort(pos.begin(), pos.end());
    sort(aux.begin(), aux.end());
    for(int i = 0; i < pos.size(); i++)
        a[pos[i]] = aux[i];
}


int main()
{
    FastIO;
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        for(int j = 0; j < n; j++)
            mat[i][j+1] = (tmp[j] - '0');
    }

    for(int i = 1; i <= n; i++)
        if(!visited[i])
        {
            aux.clear();
            pos.clear();
            DFS(i, a);
            func(a);
        }

    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;   
}

