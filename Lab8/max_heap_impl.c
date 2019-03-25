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
int max_heap[N], last = 1;
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
	if(par >= 1 && max_heap[par] < max_heap[j])
		swap(&max_heap[par], &max_heap[j]), Sift(par);
}

void Push(int x)
{
	max_heap[last] = x;
	if(last > 1)
		Sift(last);
	last++;
}

void Pop(int j)
{
	int l = (2*j), r = (2*j + 1), nxt = ((max_heap[l] > max_heap[r]) ? l : r);;
	if(max_heap[l] || max_heap[r])
		max_heap[j] = max_heap[nxt], Pop(nxt);
	else
		max_heap[j] = 0;	
	last--;
}
/******************************************************************************/

int main()
{
	// freopen("inp.txt", "r", stdin);
	// freopen("outp.txt", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 0, x; i < n; i++)
	{
		scanf("%d", &x);
		Push(x);
		for(int i = 1; i < last; i++)
			printf("%d ", max_heap[i]);
		printf("\n");
	}

	printf("-----------------------------------------\n");
	for(int i = 0; i < n; i++)
		printf("%d ", max_heap[1]), Pop(1);
		
	return 0;
}


