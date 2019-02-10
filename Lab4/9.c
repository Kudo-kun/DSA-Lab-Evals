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
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &k);
	if(k < arr[0])
		printf("Sasuke 1\n");
	else if(k > arr[n-1])
		printf("Sasuke %d\n", n);
	else
	{
		int x = BinSearch(0, n, k, arr);
		(arr[x] == k) ? printf("Naruto %d\n", x+1) : printf("Sasuke %d\n", x+2);
	}
    return 0;
}
