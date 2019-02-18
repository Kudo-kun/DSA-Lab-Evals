//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105
#define ll long long int

int n, ans;
/******************************************************************************/
void merge(int l1, int r1, int l2, int r2, int arr[])
{
	int aux[r2-l1+2], cnt = 0, k = l1;
	while(l1 <= r1 && l2 <= r2)
	{
		if(arr[l1] <= arr[l2])
			aux[cnt++] = arr[l1++];
		else
		{
			aux[cnt++] = arr[l2++];
			ans += (r1-l1+1);
		}
	}
	while(l1 <= r1)
		aux[cnt++] = arr[l1++];
	while(l2 <= r2)
		aux[cnt++] = arr[l2++];
	for(int i = 0; i < cnt; i++)
		arr[i+k] = aux[i];
}



void sort(int lo, int hi, int arr[])
{
	if(lo < hi)
	{
		int mid = (lo + hi)/2;
		sort(lo, mid, arr);
		sort(mid+1, hi, arr);
		merge(lo, mid, mid+1, hi, arr);
	}
}
/******************************************************************************/

int main()
{	
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", arr+i);
	
	sort(0, n, arr);
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n%d\n", ans);
	return 0;
}
