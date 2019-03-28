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


int n, nidx, ans;
int nheap[N];
/******************************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
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
		if(nidx > 1 && nheap[1] < u)
			ans += (u - nheap[1]), Popn(), Pushn(u);
		Pushn(u);
	}

	printf("Minimum no. of updations: %d\n", ans);
	return 0;
}


