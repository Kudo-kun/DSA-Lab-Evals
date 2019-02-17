//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105
#define ll long long int

int n, src = INT_MAX, dia, cnt;
/******************************************************************************/
int max(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}


int find(int k, int arr[])
{
	for(int i = 0; i < n; i++)
		if(arr[i] == k)
			return i;

	return -1;
}


int getCount(int k, int arr[])
{
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(arr[i] == k)
			ans++;

	return ans;
}


void makeCycle(int k, int arr[])
{
	for(int i = 0, init, flag = 0; i < n; i++)
	{
		if(arr[i] == k && !flag)
			{flag = 1; init = i;}
		else if(arr[i] == k && flag)
			{printf("%d %d\n", init+1, i+1); return;}
	}
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if(!arr[i])
			src = i;

		dia = max(dia, arr[i]);
	}

	if(src == INT_MAX)
	{
		printf("-1\n");
		return 0;
	}

	for(int d = 1; d <= dia; d++)
	{
		int j = find(d-1, arr);
		for(int i = 0; i < n; i++)
			if(arr[i] == d)
			{
				printf("%d %d\n", i+1, j+1);
				cnt++;
			}
	}

	if(cnt < n)
		for(int i = 1; i <= n; i++)
			if(getCount(i, arr) >= 2)
			{
				makeCycle(i, arr);
				break;
			}
	
	return 0;
}
