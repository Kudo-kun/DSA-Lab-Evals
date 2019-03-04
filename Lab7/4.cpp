//Author: Kudo_kun
//1061B
#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long int

const int N = 1e5+5;
ll n, y = 1, stk[N], sum, m;

int main()
{
	cin >> n >> m;
	for(ll i = 0; i < n; i++)
	{
		cin >> stk[i];
		sum += stk[i];
	}

	sort(stk, stk+n);
	for(ll i = 1; i < n; i++)
		if(y < stk[i])
			y++;
	
	cout << (sum - (n + stk[n-1] - y)) << endl;
    return 0;   
}