//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, tot, ans = INT_MAX, num, ht;
/******************************************************************************/
int getOnes(int k)
{
	int cnt = 0;
	for(ll i  = (1 << n); i > 0; i >>= 1)
		if(i&k)
			cnt++;

	return cnt;
}


int getCost(int k, int m, int arr[], int cost[])
{
	int fin = 0;
	for(int i = 1, j = 0; i < (1 << n); i <<= 1, j++)
		fin += (i&k) ? abs(arr[j]-m)*cost[j] : (arr[j]*cost[j]);

	return fin;
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	int arr[n], cost[n];

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		tot += arr[i]; 
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &cost[i]);

	for(int i = 1, x, y; i < (1 << n); i++)
	{
		x = getOnes(i);
		if(!(tot % x))
		{
			y = getCost(i, tot/x, arr, cost);
			if(y < ans)
			{
				ans = y;
				num = x;
				ht = tot/x;
			}	
		}
	}
			

	printf("%d, %d, %d\n", ans, num, ht);
	return 0;
}
