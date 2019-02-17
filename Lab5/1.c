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
		int ans[n], cnt1 = 0, cnt2 = 0;
		Triple arr[n];
		for(int i = 0, l, r; i < n; i++)
		{
			scanf("%d%d", &arr[i].first, &arr[i].second);
			arr[i].j = i;
		}

		sort(arr);
		for(int i = 0; i < n; i++)
		{
			if(!i)
			{
				ans[arr[i].j] = 1;
				cnt1++;
			}
			else
			{
				int l = arr[i].first, L = arr[i-1].first, R = arr[i-1].second;
				ans[arr[i].j] = ((l >= L && l <= R) ? ans[arr[i-1].j] : !ans[arr[i-1].j]);
				(l >= L && l <= R) ? cnt1++ : cnt2++;
			}
		}
		(!cnt1 || !cnt2) ? printf("-1\n") : PrintList(ans);
	}
	return 0;
}
