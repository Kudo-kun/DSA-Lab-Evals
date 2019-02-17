//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int T, n;
/******************************************************************************/
typedef struct tupletyple
{
	int first, second, j;
} Triple;


int max(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}


void swap(Triple* a, Triple* b)
{
	Triple c = *a;
	*a = *b;
	*b = c;
}


void sort(Triple arr[])
{
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if(arr[i].first > arr[j].first)
				swap(arr+i, arr+j);
}


void PrintList(int arr[])
{
	for(int i = 0; i < n; i++)
		(arr[i] == 1) ? printf("IM ") : printf("CA ");
	printf("\n");
}
/******************************************************************************/

int main()
{	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int ans[n];
		Triple arr[n];
		for(int i = 0, l, r; i < n; i++)
		{
			scanf("%d%d", &arr[i].first, &arr[i].second);
			arr[i].j = i;
		}

		sort(arr);
		int Rmax = arr[0].first, i;
		for(i = 0; i < n; i++)
		{
			if(arr[i].first > Rmax)
				break;
			Rmax = max(Rmax, arr[i].second);
		}

		if(i == n)
			printf("-1\n");
		else
		{
			for(int x = 0; x < i; x++)
				ans[arr[x].j] = 1;
			for(int x = i; x < n; x++)
				ans[arr[x].j] = 2;
			PrintList(ans);
		}
	}
	return 0;
}
