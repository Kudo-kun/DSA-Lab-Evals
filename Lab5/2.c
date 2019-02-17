//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 107
#define ll long long int

int n, m, flist[N];
/******************************************************************************/



/******************************************************************************/

int main()
{
	scanf("%d%d", &n, &m);
	int a1[n], a2[m];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a1[i]);
		flist[a1[i]]++;
	}
	for(int i = 0; i < m; i++)
		scanf("%d", &a2[i]);

	for(int i = 0; i < m; i++)
		while(flist[a2[i]])
		{
			printf("%d ", a2[i]);
			flist[a2[i]]--;
		}

	for(int i = 0; i < N; i++)
		while(flist[i])
		{
			printf("%d ", i);
			flist[i]--;
		}

	return 0;
}
