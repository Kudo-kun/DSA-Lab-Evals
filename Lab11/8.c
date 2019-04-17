#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 55
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long

int n, k, t;
/******************************************************************/
/******************************************************************/

int main()
{	
	scanf("%d%d%d", &n, &k, &t);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", arr+i);

	for(int i = 0; i < n; i++)
		for(int j = (i+1); j < n; j++)
			if((abs(arr[i]-arr[j]) <= t) && (abs(i-j) <= k))
				return printf("Hogwarts Wins!!!\n"), 0;

	printf("Voldemort Wins!!!\n");
	return 0;
}



       
       


