#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n, m, x, sum, ans;
int stk1[N], top1;
int stk2[N], top2;
/******************************************************************/
/******************************************************************/

int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 0; i < n; i++, top1++)
		scanf("%d", &stk1[n-i-1]);
	for(int i = 0; i < m; i++, top2++)
		scanf("%d", &stk2[m-i-1]);

	--top1; --top2;
	while(sum <= x)
		sum += (((stk1[top1] <= stk2[top2] && top1) || !top2) ? stk1[top1--] : stk2[top2--]), ans++;

	printf("Total number of elements popped are: %d\n", --ans);
	return 0;
}