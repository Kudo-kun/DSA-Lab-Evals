//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105
#define ll long long int


int n, q, list[N];
/******************************************************************************/
typedef struct tupletype
{
	int id, L, R;
} Triple;


int min(int a, int b)
{
	if(a <= b)
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
			if(arr[i].L > arr[j].L || ((arr[i].L == arr[j].L) && (arr[i].R > arr[j].R)))
				swap(arr+i, arr+j);
}


int occupied(int L, int R)
{
	for(int i = L; i <= R; i++)
		if(list[i])
			return list[i];

	return 0;
}


void fill(int k, int L, int R)
{
	for(int i = L; i <= R; i++)
		list[i] = k;
}
/******************************************************************************/

int main()
{
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &n);
		Triple arr[n];
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &arr[i].L, &arr[i].R);
			arr[i].id = i;
		}

		int c[4], ans[n];
		memset(list, 0, N*sizeof(int));
		memset(ans, 0, n*sizeof(int));
		memset(c, 0, 4*sizeof(int));
		sort(arr);
		for(int i = 0; i < n; i++)
		{
			int k = occupied(arr[i].L, arr[i].R);
			if(!k)
			{
				if(c[1] == min(c[1], c[2]))
				{
					fill(1, arr[i].L, arr[i].R);
					c[1]++;
					ans[arr[i].id] = 1;
				}
				else if(c[2] == min(c[1], c[2]))
				{
					fill(2, arr[i].L, arr[i].R);
					c[2]++;
					ans[arr[i].id] = 2;
				}
			}
			else
			{
				fill(k, arr[i].L, arr[i].R); 
				c[k]++;
				ans[arr[i].id] = k;
			}
		}
		if(!c[1] || !c[2])
			printf("-1");
		else
			for(int i = 0; i < n; i++)
				(ans[i] == 1) ? printf("CA ") : printf("IM ");
		
		printf("\n");
	}
	return 0;
}
