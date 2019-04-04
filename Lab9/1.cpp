//Author: Kudo_kun
#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long int
#define ld long double

const int N = (2e5 + 5);
int n, thres, T, ans;
struct Process
{
	int arr;
	int exe;
	int prev_relinquish_time;
};

queue<Process> qp;

int main()
{
    FastIO;
    cin >> n;
    for(int i = 0, a, b; i < n; i++)
    {
    	cin >> a >> b;
    	Process pro;
    	pro.exe = b;
    	pro.arr = a;
    	pro.prev_relinquish_time = a;
    	qp.push(pro);
    }

    cin >> thres;
    while(!qp.empty())
    {
    	Process tmp = qp.front();
    	if(tmp.arr <= T)
    	{
    		int v = min(tmp.exe, thres);
    		tmp.exe -= v;
    		ans += (T - tmp.prev_relinquish_time);
    		T += v;
    		tmp.prev_relinquish_time = T;
    		qp.pop();
    		if(tmp.exe)
    			qp.push(tmp);
    	}
    	else
    		T++;
    }

    cout << (float)ans/n << endl;
    return 0;
}
