//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long long int
#define N 50
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n;
/******************************************************************************/
int digitCount(int x)
{
	int cnt;
	for(cnt = 0; cnt < 12 && x; cnt++)
		x /= 10;

	return cnt;
}


int cmp(const void* a, const void* b)
{
	int x = (*(const int*)a), y = (*(const int*)b);
	int c = x*pow(10, digitCount(y)) + y;
	int d = y*pow(10, digitCount(x)) + x;
	return (c < d);
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	qsort(arr, n, sizeof(int), cmp);
	for(int i = 0; i < n; i++)
		printf("%d", arr[i]);
	return 0;
}


