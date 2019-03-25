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


int curr_time, n;
double wait_time;
/******************************************************************************/
typedef struct pairtype
{
	int st, pro, stat;
} Pair;


int find(Pair arr[])
{
	int idx = 0, val = INT_MAX;
	for(int i = 0; i < n; i++)
		if(arr[i].st < curr_time && !arr[i].stat && arr[i].pro < val)
			val = arr[i].pro, idx = i;

	return idx;
}
/******************************************************************************/

int main()
{
	// freopen("inp.txt", "r", stdin);
	// freopen("outp.txt", "w", stdout);
	scanf("%d", &n);
	Pair arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d%d", &arr[i].st, &arr[i].pro), arr[i].stat = 0;

	curr_time = arr[0].st;
	curr_time += (arr[0].pro);
	wait_time += (curr_time - arr[0].st);
	arr[0].stat = 1;
	
	for(int i = 1; i < n; i++)
	{
		int idx = find(arr);
		arr[idx].stat = 1;
		curr_time += (arr[idx].pro);
		wait_time += (curr_time - arr[idx].st);
	}

	printf("\nAvg wait time is: %lf\n", (wait_time/n));
	return 0;
}


