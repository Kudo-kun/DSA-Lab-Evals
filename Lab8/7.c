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


int n, ans;
/******************************************************************************/
typedef struct pairtype
{
	int first;
	int second;
} Pair;


Pair setSize(int i, int arr[])
{
	Pair p;
	int l, r;
	for(l = i; l > 0 && arr[l-1] >= arr[i]; l--){}
	for(r = i; r < (n-1) && arr[r+1] >= arr[i]; r++){}

	p.first = (i-l), p.second = (r-i);
	return p;
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", arr+i);

	for(int i = 0; i < n; i++)
	{
		Pair p = setSize(i, arr);
		ans += (arr[i]*(p.first + 1)*(p.second + 1));
	}
	
	printf("\nTotal sum is: %d\n", ans);
	return 0;
}


