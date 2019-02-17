//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105
#define ll long long int

int n, l, sum, ans;
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
				swap(arr+i, arr+j);

	while(!arr[l])
		l++;
}


void func(int k, int arr[])
{
	for(int i = 0; i < n; i++)
		if(arr[i] % 3 == k)
		{
			arr[i] = -1;
			return;
		}
	
	arr[l] = -1;
	arr[l+1] = -1;
	return;
}
/******************************************************************************/

int main()
{	
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr+i);
		sum += arr[i];
	}

	sort(arr);
	if(sum % 3)
		func(sum % 3, arr);
	for(int i = n-1; i >= 0; i--)
		if(arr[i] != -1)
			ans = (ans*10 + arr[i]);	

	printf("%d\n", ans);
	return 0;
}
