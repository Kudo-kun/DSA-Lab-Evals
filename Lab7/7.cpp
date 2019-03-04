//Author: Kudo_kun
//302B
#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long int

const int N = 105;
int n, ans;
pair<int, int> pa[N];

int find(int k, int arr[])
{
    for(int i = 0; i < n; i++)
        if(arr[i] == k)
            return i;
    
    return -1;
}


int main()
{
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i];

    sort(b, b+n);
    for(int i = 0; i < n; i++)
        pa[i] = {i, find(a[i], b)};

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if((pa[i].first < pa[j].first) && pa[i].second > pa[j].second)
                ans++;

    cout << ans << endl;
    return 0;
}