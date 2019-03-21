//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long int
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int n, k, ans;
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
		for(int j = i+1; j < n; j++)
			if(arr[j] < arr[i])
				swap(arr + i, arr + j);
}
/******************************************************************************/

int main()
{
	scanf("%d%d", &n, &k);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", arr+i);

	sort(arr);
	for(int i = 0; i < (n-1); i++)
		if(arr[i] < k)
			arr[i+1] = (arr[i] + 2*arr[i+1]), ans++;
	
	printf("Total no. of operations: %d\n", ans);
	return 0;
}


