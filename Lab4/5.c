//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, m;
/******************************************************************************/
int Items(int t, int arr[])
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += (t / arr[i]);

	return sum;
}


int BinSearch(int lo, int hi, int arr[])
{
	
	while(lo !=  hi)
	{
		int mid = (lo + hi)/2;
		if(Items(mid, arr) > m)
			hi = mid-1;
		else if(Items(mid, arr) == m)
			return mid;
		else if(Items(mid, arr) < m)
			lo = mid+1;
	}
	return lo;
}

/*****************************************************************************/

int main()
{
	scanf("%d%d", &n, &m);
	int arr[n], min = INT_MAX, max = INT_MIN;

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i] < min)
			min = arr[i];
		else if(arr[i] > max)
			max = arr[i];
	}

	int min_time = (m/max), max_time = (m/min);
	printf("%d\n", BinSearch(min_time, max_time, arr));
    return 0;
}
