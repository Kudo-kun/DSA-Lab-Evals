//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, ans;
int visited[N], sorted_pos[N];
/******************************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


void sort(int arr[])
{
	memset(sorted_pos, -1, N*sizeof(int));
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if(arr[j] < arr[i])
			{
				//swap(arr+i, arr+j);
				int c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
}


/******************************************************************************/

int main()
{
	// freopen("test.c", "r", stdin);
	// freopen("output.c", "w", stdout);
	scanf("%d", &n);
	int a[n], b[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	sort(b);
	for(int i = 0, cnt = 0; i < n; i++)
	{
		int j = sorted_pos[a[i]];
		visited[a[i]] = 1;
		if(j != i && !visited[a[j]])
		{
			visited[a[j]] = 1;
			cnt++;
		}
		else if(visited[a[j]] && j != i)
		{
			ans += cnt;
			cnt = 0;
		}
	}

	printf("%d\n", ans);
	return 0;
}
