//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long long int

int n, dp[10005];
/******************************************************************************/
int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}


int optSolution(int N)
{
	for(int i = 7; i <= N && N >= 7; i++)
		for(int j = 0; j <= (i-3); j++)
			dp[i] = max(dp[i], dp[j]*(i-j-1));
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < 7; i++)
		dp[i] = i;
	
	optSolution(n);
	for(int i = 1; i <= n; i++)
		printf("%d ", dp[i]);
	printf("\n%d\n", dp[n-1]);
	return 0;
}


