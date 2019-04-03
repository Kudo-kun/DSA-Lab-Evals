#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int k, n, m, ans;
int stk1[N];
int stk2[N];
/******************************************************************/


/******************************************************************/

int main()
{
	int sum = 0, i = 0, j = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &stk1[i]);
	for(int i = 0; i < m; i++)
		scanf("%d", &stk2[i]);

	while(i < n && ((sum + stk1[i]) <= k))
		sum += stk1[i++];

	ans = i;
	while(j < m && i >= 0)
	{
		sum += stk2[j++];
		while(sum > k && i > 0)
			sum -= stk1[--i];
		if(sum <= k && (i+j) > ans)
			ans = (i+j);
	}

	printf("%d\n", ans);
	return 0;
}



       
       


