//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, cnt;
char s1[N], s2[N];
/******************************************************************************/
int helper(int* init, char ch, char str[])
{
	for(; *init < strlen(s1); (*init)++)
		if(str[(*init)] == ch)
			{(*init)++; return 1;}

	return 0;
}


int func()
{
	for(int i = 0, init = 0; i < strlen(s2) && init < strlen(s1); i++)
		if(!helper(&init, s2[i], s1))
			return 0;

	return 1;
}
/******************************************************************************/

int main()
{
	scanf("%s%s%d", s1, s2, &n);
	int arr[n];

	for(int i = 0, j; i < n; i++)
		scanf("%d", &arr[i]);

	for(int i = 0, j; i < n; i++)
	{
		j = arr[i]-1;
		s1[j] = '-';
		if(func())
			cnt++;
		else
			break;
	}

	printf("\n%d\n", cnt);
	return 0;
}
