//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, ans, k;
/******************************************************************************/
int BinSearch(int lo, int hi, int x, int arr[])
{
	while(lo < hi)
	{
		int mid = (lo + hi)/2;
		if(x > arr[mid])
			lo = mid+1;
		else if(x == arr[mid])
			return (mid % n);
		else if(x < arr[mid])
			hi = mid-1;
	}
}

/******************************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[2*n], pos, min = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		arr[i+n] = arr[i];
		if(arr[i] < min)
		{
			min = arr[i];
			pos = i;
		}
	}

	scanf("%d", &k);
	printf("Position of element is: %d\n", BinSearch(pos, pos+n, k, arr));
    return 0;
}
