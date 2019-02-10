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
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


int BinSearch(int lo, int hi, int x, int arr[])
{
	while(lo != hi)
	{
		int mid = (lo + hi)/2;
		if(x > arr[mid])
			lo = mid+1;
		else if(x == arr[mid])
			return mid;
		else if(x < arr[mid])
			hi = mid-1;
	}
	return lo;
}

/*****************************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n], swap_elem = INT_MAX;

	scanf("%d", &arr[0]);
	for(int i = 1; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i] < arr[i-1])
		{
			swap_elem = arr[i-1];
			swap(&arr[i], &arr[i-1]);
		}
	}

	scanf("%d", &k);
	int x = BinSearch(0, n, k, arr);
	if(arr[x] != k)
		x = -2;
	else if(arr[x] == k && arr[x] == swap_elem)
		x--;

	printf("\n%d\n", x+1);
    return 0;
}
