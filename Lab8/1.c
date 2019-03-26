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


int n, xidx, nidx;
double med;
int xheap[N], nheap[N];
/******************************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Pushx(int u)
{
	xheap[++xidx] = u;
	int i = xidx;
	while(i > 1 && xheap[i/2] < xheap[i])
		swap(&xheap[i], &xheap[i/2]), (i /= 2);
}

int Popx()
{
	int val = xheap[1], i = 1;
	xheap[1] = xheap[xidx--];
	while(1 && i < xidx)
	{
		if(xheap[2*i] > xheap[2*i + 1])
			swap(&xheap[i], &xheap[2*i]), (i *= 2);
		else if(xheap[2*i] < xheap[2*i + 1])
			swap(&xheap[i], &xheap[2*i + 1]), (i = (2*i + 1));
		else
			break;
	}
	return val;
}



void Pushn(int u)
{
	nheap[++nidx] = u;
	int i = nidx;
	while(i > 1 && nheap[i/2] > nheap[i])
		swap(&nheap[i], &nheap[i/2]), (i /= 2);
}

int Popn()
{
	int val = nheap[1], i = 1;
	nheap[1] = nheap[nidx--];
	while(1 && i < nidx)
	{
		if(nheap[2*i] < nheap[2*i + 1])
			swap(&nheap[i], &nheap[2*i]), (i *= 2);
		else if(nheap[2*i] > nheap[2*i + 1])
			swap(&nheap[i], &nheap[2*i + 1]), (i = (2*i + 1));
		else
			break;
	}
	return val;
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	for(int i = 0, u; i < n; i++)
	{
		scanf("%d", &u);
		(u < med) ? Pushx(u) : Pushn(u);
		if(xidx - nidx > 1)
			Pushn(Popx());
		else if(nidx - xidx > 1)
			Pushx(Popn());
		
		med = ((xidx > nidx) ? xheap[1] : ((xidx < nidx) ? nheap[1] : (((double)xheap[1] + (double)nheap[1])/2)));
		printf("Current median is: %lf\n", med);
	}

	return 0;
}


