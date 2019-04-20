#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long

int n, pre[N], in[N];
int Tree[N], tidx;
int sig1, sig2;
/***************************************************************************************************************************/
int find(int x, int arr[])
{
	for(int i = 0; i < n; i++)
		if(arr[i] == x)
			return i;
}


void gen_Tree(int curr_root, int pos)
{
	int j = find(curr_root, in);
	if(j == 0)
		sig1 = 1;
	if(j == n-1)
		sig2 = 1;
	
	Tree[pos] = curr_root;
	if(!sig1)
		gen_Tree(pre[++tidx], 2*pos);
	else
		return;
	if(!sig2)
		gen_Tree(pre[++tidx], 2*pos + 1);
	else
		return;
}


void PO_Traversal(int j)
{
	if(Tree[j] == -1)
		return;
	PO_Traversal(2*j);
	PO_Traversal(2*j + 1);
	printf("%d ", Tree[j]);
}
/***************************************************************************************************************************/

int main()
{	
	memset(Tree, -1, N*sizeof(int));
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", in+i);
	for(int i = 0; i < n; i++)
		scanf("%d", pre+i);
	gen_Tree(pre[tidx], 1);
	printf("Post Order of given Tree is :: ");
	PO_Traversal(1);
	return 0;
}



       
       


