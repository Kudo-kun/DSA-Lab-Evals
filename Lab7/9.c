//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long long int
#define N 50
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n, max_dig;
/******************************************************************************/
typedef struct pairtype
{
	int first, second, X;
} Pair;


int digitCount(int x)
{
	int cnt;
	for(cnt = 0; cnt < 12 && x; cnt++)
		x /= 10;

	return cnt;
}


void sort(Pair arr[])
{
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if((arr[i].second < arr[j].second) || ((arr[i].second == arr[j].second) && (arr[j].first < arr[i].first)))
			{
				Pair c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
}
/******************************************************************************/

int main()
{
	scanf("%d", &n);
	Pair arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i].first), arr[i].X = digitCount(arr[i].first), max_dig = max(max_dig, arr[i].X);
	for(int i = 0; i < n; i++)
		arr[i].second = (arr[i].first * pow(10, (max_dig - arr[i].X)));
	
	sort(arr);
	for(int i = 0; i < n; i++)
		printf("%d", arr[i].first);
	
	printf("\n");
	return 0;
}


