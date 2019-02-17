//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, ans = INT_MAX;
/******************************************************************************/
int min(int a, int b)
{
	if(a <= b)
		return a;
	else
		return b;
}


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
				swap(arr+i, arr+j);
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr);
	if(arr[n-1] <= 2*arr[0])
	{
		printf("0\n"); 
		return 0;
	}

	for(int i = 0; i < n; i++)
	{
		int j = i;
		while(arr[j] <= 2*arr[i] && j < n) 
			j++;
		if(arr[j] > 2*arr[i])
			j--;

		ans = min(ans, n-j+i-1);
	}


	printf("\n%d\n", ans);
	return 0;
}
