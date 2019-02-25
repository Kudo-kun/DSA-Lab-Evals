//Author: Kudo_kun
//978B
#include<bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long int
#define N 200005
#define INF 1000000000

typedef struct Car
{
    int cost, cap;
} Car;

Car a[N];
int g[N], d[N], k, t;

//basic pair sorting function;
bool leq(Car a, Car b)
{
    if(a.cap == b.cap)
        return a.cost < b.cost;
    return a.cap < b.cap;
}

int check(int x)
{
    // cap = current_car's capacity;
    int cap = a[x].cap, time = 0;
    for(int i = 0; i <= k; ++i)
    {
        //if distance between two successive gas stations is greater than cap, we need a car with a better tank;
        if(d[i] > cap)
            return 1;
        time += max(3*d[i] - cap, d[i]);
    }
    //if the time of travel is greater than 't', we take a car with better capacity;
    return time > t;
}

int binsearch(int lo, int hi)
{
    while(lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(check(mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}

int32_t main()
{
    int n, s;
    //take all inputs;
    cin >> n >> k >> s >> t;
    for(int i = 0; i < n; ++i)
        cin >> a[i].cost >> a[i].cap;
    for(int i = 0; i < k; ++i)
        cin >> g[i];
    
    //last gas station is at the end of the road;
    g[k] = s;
    
    //sort the cars and the gas stations accordingly;
    sort(a, a+n, leq);
    sort(g, g+k+1);
    
    //d[N] represents the distances between the successive gas stations;
    d[0] = g[0];
    for(int i = 1; i <= k; ++i)
        d[i] = g[i] - g[i-1];
    
    //assume last car's capacity is INF;
    a[n].cap = INF;
    
    //use binary search to the car such that u can reduce your time optimally to 't';
    int cap = a[binsearch(0, n-1)].cap, ans = INF;

    //if any car's capacity is greater than the cap we calculated, we find it's cost, such that it's minimum;
    for(int i = 0; i < n; ++i)
        if(a[i].cap >= cap)
            ans = min(ans, a[i].cost);
    
    //if ans is still INF, no answer is possible;
    if(ans == INF)
        return printf("-1\n"), 0;
    printf("%d\n", ans);
    return 0;
}