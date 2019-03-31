#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n;
/******************************************************************/
typedef struct pairtype
{
	int pet, dist;
} Pair;


int check(int j, Pair arr[])
{
	int sum = 0, stop = j;
	while(1)
	{
		sum += (arr[stop].pet);
		sum -= (arr[stop].dist);
		if(sum < 0)
			return 0;

		stop++;
		if(stop > n-1)
			stop %= n;
		if(stop == j)
			return 1;
	}
}


/******************************************************************/

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("outp.txt", "w", stdout);
	
	scanf("%d", &n);
	Pair arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d%d", &arr[i].pet, &arr[i].dist);

	for(int i = 0; i < n; i++)
		if(check(i, arr))
			return printf("Tour starts at stop no. %d\n", i), 0;

	return 0;
}