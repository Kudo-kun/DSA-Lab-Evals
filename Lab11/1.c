#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n, sum;
int ty1, ty2;
/******************************************************************/
/******************************************************************/

int main()
{
	scanf("%d%d", &sum, &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", arr+i);

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if(((arr[i] + arr[j]) == sum) && (arr[i] != arr[j]))
			{
				ty1 = i, ty2 = j;
				break;
			}
	
	(arr[ty1] < arr[ty2]) ? printf("%d %d\n", arr[ty1], arr[ty2]) : printf("%d %d\n", arr[ty2], arr[ty1]);
	return 0;
}



       
       


