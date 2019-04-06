#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define Median(a, b) (((double)a + (double)b)/2)

int n;
int xidx, xheap[N];
int nidx, nheap[N];
double med;
/******************************************************************/
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
	while(i > 1 && xheap[i] > xheap[i/2])
		swap(&xheap[i], &xheap[i/2]), (i >>= 1);
}

void Pushn(int u)
{
	nheap[++nidx] = u;
	int i = nidx;
	while(i > 1 && nheap[i] < nheap[i/2])
		swap(&nheap[i], &nheap[i/2]), (i >>= 1);
}


int Popx()
{
	int val = xheap[1], i = 1;
	xheap[1] = xheap[xidx--];
	while(1 && i < xidx)
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

int Popn()
{
	int val = nheap[1], i = 1;
	nheap[1] = nheap[nidx--];
	while(1 && i < nidx)
	{
		if(nheap[2*i] < nheap[2*i + 1])
			swap(&nheap[i], &nheap[2*i]), (i <<= 1);
		else if(nheap[2*i] > nheap[2*i + 1])
			swap(&nheap[i], &nheap[2*i + 1]), (i = (2*i + 1));
		else
			break;
	}
	return val;	
}
/******************************************************************/

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

		if(xidx > nidx)
			med = xheap[1];
		else if(nidx > xidx)
			med = nheap[1];
		else
			med = Median(xheap[1], nheap[1]);

		printf("current median is: %lf\n", med);
	}
	
	return 0;
}



       
       


