#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int n, k, x;
int left[N], right[N], totals[N];
/******************************************************************/
int cmp(const void* a, const void* b)
{
	int u = (*(const int*)a), v = (*(const int*)b);
	return (u < v);

}/******************************************************************/

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", left+i);
	for(int i = 0; i < n; i++)
		scanf("%d", right+i);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			totals[x++] = left[i] + right[j];

	qsort(totals, x, sizeof(int), cmp);
	for(int i = 0; i < k; i++)
		printf("%d ", totals[i]);
	return 0;
}



       
       


