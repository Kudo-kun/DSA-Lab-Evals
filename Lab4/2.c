//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, k;
/******************************************************************************/
int count(int v, int k)
{
	int sum = 0;
	while(v)
	{
		sum += v;
		v /= k;
	}
	return sum;
}


int BinSearch(int lo, int hi, int k)
{
	while(lo != hi)
	{
		int mid = (lo + hi)/2;
		if(count(mid, k) > n)
			hi = mid-1;
		else if(count(mid, k) == n)
			return mid;
		else if(count(mid, k) < n)
			lo = mid+1;
	}
	return lo;
}


/******************************************************************************/

int main()
{
	scanf("%d%d", &n, &k);
	printf("%d\n", BinSearch(0, n, k));
    return 0;
}
