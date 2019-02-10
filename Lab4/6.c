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
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


void sort(int arr[])
{
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if(arr[j] < arr[i])
				swap(arr+j, arr+i);
}


int BinSearch(int lo, int hi, int x, int arr[])
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2; 
		if (x == arr[mid])
			return mid;
		else if (x < arr[mid])
			hi = mid - 1;
		else
			lo = mid + 1;
   }
   return -1;
}

/*****************************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", arr+i);

	scanf("%d", &k);
	sort(arr);

	for(int i = 0; i < n; i++)
	{
		int j1 = BinSearch(0, n, k+arr[i], arr), j2 = BinSearch(0, n, arr[i]-k, arr);
		if(j1 != -1)
		{
			printf("sum is: %d\n", arr[i]+arr[j1]);
			return 0;
		}
		else if(j2 != -1)
		{
			printf("sum is: %d\n", arr[i]+arr[j2]);
			return 0;
		}
	}
    
	printf("-1\n");
    return 0;
}
