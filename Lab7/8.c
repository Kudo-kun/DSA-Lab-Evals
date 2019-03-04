//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long long int
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n;
/******************************************************************************/
int test(int x)
{
	int j = 0, arr[N];
	if(x >= 0 && x <= 9)
		return 1;
	while(x)
	{
		arr[j++] = (x % 10);
		x /= 10;
	}

	for(int i = 1; i < j; i++)
		if(abs(arr[i] - arr[i-1]) != 1)
			return 0;

	return 1;	
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	for(int i = 0; i <= n; i++)
		if(test(i))
			printf("%d ", i);
	
	return 0;
}


