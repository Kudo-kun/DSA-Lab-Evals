#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int T, dp[N], k;
/******************************************************************/
int dynamicInit(int n)
{
	if(dp[n])
		return dp[n];
	
	int x = (dynamicInit(n-1) + 1), ans_len = INT_MAX;
	for(int j = 2; j*j <= n; j++)
		if(!(n % j))
			ans_len = (min(ans_len, dynamicInit(max(j, n/j))) + 1);

	dp[n] = min(ans_len, x);
}

/******************************************************************/

int main()
{
	scanf("%d", &T);
	dp[0] = 1;
	dp[2] = 2;
	dp[3] = dp[4] = 3;
	while(T--)
		scanf("%d", &k), printf("%d\n", dynamicInit(k));

	return 0;
}