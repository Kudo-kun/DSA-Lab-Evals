#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n;
int nidx, nheap[N];
/******************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Push(int u)
{
	nheap[++nidx] = u;
	int i = (nidx - 1);
	while(i > 1 && nheap[i] < nheap[i/2])
		swap(&nheap[i], &nheap[i/2]), (i >>= 1);
}

int check(int arr[])
{
	for(int i = 0; i < n; i++)
		printf("%d %d\n", nheap[i+1], arr[i]);
	printf("\n");
	for(int i = 0; i < n; i++)
		if(arr[i] != nheap[i+1])
			return 0;

	return 1;
}
/******************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", arr+i), Push(arr[i]);
	(check(arr)) ? printf("True\n") : printf("False\n");
	return 0;
}



       
       


