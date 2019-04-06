#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1105
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n, k, ans;
int xidx, xheap[N];
/******************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


int Push(int u)
{
	xheap[++xidx] = u;
	int i = xidx;
	while(i > 1 && xheap[i] > xheap[i/2])
		swap(&xheap[i], &xheap[i/2]), (i /= 2);
}


int update_and_heapify()
{
	int val = xheap[1], i = 1;
	xheap[1] >>= 1;
	while(1 && i <= xidx)
	{
		if(xheap[2*i] > xheap[2*i + 1])
			swap(&xheap[i], &xheap[2*i]), (i <<= 1);
		else if(xheap[2*i] < xheap[2*i + 1])
			swap(&xheap[i], &xheap[2*i + 1]), (i <<= 1), (i++);
		else
			break;
	}
	return val;
}
/******************************************************************/

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0, u; i < n; i++)
		scanf("%d", &u), Push(u);
	for(int i = 0; i < k; i++)
		ans += update_and_heapify();
	printf("Max is: %d\n", ans);
	return 0;
}



       
       


