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


int n, ans;
int min_heap[N], last = 1;
/******************************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Sift(int j)
{
	int par = j/2;
	if(par >= 1 && min_heap[par] > min_heap[j])
		swap(&min_heap[par], &min_heap[j]), Sift(par);
}

void Push(int x)
{
	min_heap[last] = x;
	if(last > 1)
		Sift(last);
	last++;
}

void Pop(int j)
{
	int l = (2*j), r = (2*j + 1), nxt;
	if(min_heap[l] && min_heap[l] < min_heap[r] || !min_heap[r])
		nxt = l;
	else if(!min_heap[l] || min_heap[r])
		nxt = r;

	if(min_heap[l] || min_heap[r])
		min_heap[j] = min_heap[nxt], Pop(nxt);
	else
		min_heap[j] = 0;
	last--;
}
/******************************************************************************/

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("outp.txt", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		if(last != 1 && (min_heap[1] < x))
			ans += (x - min_heap[1]), Pop(1);
		Push(x);
	}

	printf("Total operations: %d\n", ans);
	return 0;
}


