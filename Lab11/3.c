#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long

int n, k, t, flag;
int Tree[N], root;
int st[N], cnt;
/***************************************************************************************************************************/
void Find_Insert(int x, int y)
{
	for(int i = 1; i <= N; i++)
		if(Tree[i] == x)
		{
			(Tree[2*i] == -1) ? (Tree[2*i] = y) : (Tree[2*i + 1] = y);
			return;
		}
}


int check()
{
	int flag = 0;
	for(int i = 0; i < cnt-1; i++)
		if(st[i+1] < st[i])
			return 0;

	return 1;
}


void Traverse(int u, int st[])
{
	if(Tree[u] == -1)
		return;
	Traverse(2*u, st);
	st[cnt++] = Tree[u];
	Traverse(2*u + 1, st);
}


void SubTreeChecker(int u)
{
	if(flag)
		return;
	cnt = 0, memset(st, 0, N*sizeof(int));
	Traverse(u, st);
	if(check())
	{
		flag = 1, printf("%d\n", cnt);
		for(int i = 0; i < cnt; i++)
			printf("%d ",st[i]);
	}
	
	SubTreeChecker(2*u);
	SubTreeChecker(2*u + 1);			
} 
/***************************************************************************************************************************/

int main()
{	
	memset(Tree, -1, N*sizeof(int));
	scanf("%d", &n);
	for(int i = 0, u, v; i < n-1; i++)
	{
		scanf("%d%d", &u, &v);
		if(!i) 
			Tree[1] = u;
		Find_Insert(u, v);
	}

	scanf("%d", &root);
	SubTreeChecker(1);
	return 0;
}



       
       


