#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define null -999
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long

int n, Tree[N], root;
int lo, hi;
/***************************************************************************************************************************/
void Find_Insert(int x, int y)
{
	for(int i = 1; i <= N; i++)
		if(Tree[i] == x)
		{
			(y < Tree[i]) ? (Tree[2*i] = y) : (Tree[2*i + 1] = y);
			return;
		}
}

void RIIOT(int j)
{
	if(Tree[j] == null)
		return;
	if(Tree[j] < lo)
		RIIOT(2*j + 1);
	if(Tree[j] > hi)
		RIIOT(2*j);
	if(Tree[j] >= lo && Tree[j] <= hi)
	{
		RIIOT(2*j);
		printf("%d ", Tree[j]);
		RIIOT(2*j + 1);
	}
}
/***************************************************************************************************************************/

int main()
{	
	for(int i = 0; i <= N; i++)
		Tree[i] = null;
	scanf("%d", &n);
	for(int i = 0, u, v; i < n-1; i++)
	{
		scanf("%d%d", &u, &v);
		if(!i)
			Tree[1] = u;
		Find_Insert(u, v);
	}

	scanf("%d%d%d", &root, &lo, &hi);
	RIIOT(1);
	return 0;
}



       
       


