//Author: Kudo_kun
//384B
#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long int

const int N = 1001, M = 101;
int n, m, k;
int arr[N][M];


int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0, t; j < m; j++)
			cin >> arr[i][j];

	printf("%d\n", (m*(m-1))/2);
	for(int i = 1; i <= m; i++)
		for(int j = i+1; j <= m; j++)
			(!k) ? printf("%d %d\n", i, j) : printf("%d %d\n", j, i);

  	return 0;   
}
