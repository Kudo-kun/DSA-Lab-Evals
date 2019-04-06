#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n;
int xidx, xheap[N];
/******************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Push(int u)
{
	xheap[++xidx] = u;
	int i = xidx;
	while(i > 1 && xheap[i] > xheap[i/2])
		swap(&xheap[i], &xheap[i/2]), (i >>= 1);
}
/******************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", arr+i), Push(arr[i]);
	printf("Min heap :: ");
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\nMax heap :: ");
	for(int i = 1; i <= xidx; i++)
		printf("%d ", xheap[i]);
	return 0;
}



       
       


