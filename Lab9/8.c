#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 105
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int k, w, n, tot_profit;
/******************************************************************/
typedef struct pairtype
{
	int cap, pro, comp;
} Pair;


int cmp(const void* a, const void* b)
{
	Pair x = (*(const Pair*)a), y = (*(const Pair*)b);
	int diff = (x.pro - x.cap) - (y.pro - y.cap);
	if(!diff)
		return (x.cap > y.cap);
	else
		return (diff < 0);
}

int func(Pair arr[])
{
	for(int i = 0; i < n; i++)
		if(arr[i].cap <= w && !arr[i].comp)
			return i;

	return -1;
}
/******************************************************************/

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("outp.txt", "w", stdout);
	
	scanf("%d%d%d", &k, &w, &n);
	Pair arr[n];
	for(int i = 0; i  < n; i++)
		scanf("%d", &arr[i].pro), arr[i].comp = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i].cap);

	qsort(arr, n, sizeof(Pair), cmp);
	for(int i = 0, idx; i < k; i++)
	{
		idx = func(arr);
		if(idx != -1)
		{
			tot_profit += arr[idx].pro;
			w += (arr[idx].pro - arr[idx].cap);
			arr[idx].comp = 1;
		}
		else
			break;
	}

	printf("Total profit is: %d\n", tot_profit);
	return 0;
}