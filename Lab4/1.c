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
			if(arr[i] > arr[j])
				swap(arr+i, arr+j);
}


int Cost(int m, int arr[])
{
	int sum = 0, tmp[n];
	for(int i = 0; i < n; i++)
		tmp[i] = (arr[i] + (m*(i+1)));			//modified costs according to the number of items;

	sort(tmp);
	for(int i = 0; i < m; i++)
		sum += tmp[i];

	return sum;
}
/******************************************************************************/

int main()
{
	scanf("%d%d", &n, &k);
	int arr[n], i = 1, ans;
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	while(i <= n)
	{
		int c = Cost(i, arr);
		if(c >= k)
			break;

		ans = c; i++;
	}

	i = ((i == n) ? i : (i-1));
	printf("%d %d\n", i, ans);
	return 0;
}
