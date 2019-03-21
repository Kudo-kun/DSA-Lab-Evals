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
int arr[N];
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


int getMinSum(int arr[])
{
	int u = 0, v = 0;
	for(int i = 0; i < n; i++)
		(i & 1) ? (v = (v*10 + arr[i])) : (u = (u*10 + arr[i]));

	return (u+v);
}
/******************************************************************************/

int main()
{
	for(int i = 0; i < N; i++)
	{
		char ch;
		n++;
		scanf("%d%c", &arr[i], &ch);
		if(ch == '\n')
			break;
	}

	sort(arr);
	printf("Minimum sum is: %d\n", getMinSum(arr));
	return 0;
}


