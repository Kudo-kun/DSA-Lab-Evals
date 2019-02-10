//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, ans;
/******************************************************************************/

/******************************************************************************/

int main()
{
	scanf("%d", &n);
	for(int i = 0, t; i < n; i++)
	{
		scanf("%d", &t);
		ans ^= t;
	}

	printf("%d\n", ans);
    return 0;
}
