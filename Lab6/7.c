//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long long int
#define N 105
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n, k, t, s, gas[N], d[N];
/******************************************************************************/
typedef struct
{
	int cap, cost;
} Car;

Car arr[N];


void pairSort(Car arr[])
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if((arr[i].cap < arr[j].cap) || (arr[i].cap == arr[j].cap && arr[i].cost < arr[j].cost))
			{
				Car c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
}


int check(int x)
{
	int tx = 0, capacity = arr[x].cap;
	for(int i = 0; i <= k; i++)
	{
		if(d[i] > capacity)
			return 1;
		tx += max(3*d[i]-capacity, d[i]);
	}
	return (tx > t);
}


int binSearch(int lo, int hi)
{
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(check(mid))
			lo = mid+1;
		else
			hi = mid-1;
	}
	return lo;
}


void sort(int a[])
{
	for(int i = 0; i <= k; i++)
		for(int j = 0; j <= k; j++)
			if(a[j] > a[i])
			{
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
}
/******************************************************************************/


int main()
{
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &arr[i].cost, &arr[i].cap);
	for(int i = 0; i < k; i++)
		scanf("%d", &gas[i]);

	gas[k] = s;
	pairSort(arr);
	sort(gas);
	d[0] = gas[0];
	for(int i = 1; i <= k; i++)
		d[i] = gas[i] - gas[i-1];

	arr[n].cap = INT_MAX;
	int cap = arr[binSearch(0, n-1)].cap, ans = INT_MAX;

	for(int i = 0; i < n; i++)
		if(arr[i].cap >= cap)
			ans = min(ans, arr[i].cost);

	(ans == INT_MAX) ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}
