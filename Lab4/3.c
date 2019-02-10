//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int n, flist[N];
/******************************************************************************/

/*****************************************************************************/

int main()
{
	char ch;
	for(int i = 0, t; i <= N; i++)
	{
		scanf("%d%c", &t, &ch);
		flist[t]++;
		if(ch == '\n')
			break;
	}

	for(int i = 0; i <= N; i++)
		if(flist[i] == 1)
		{
			printf("%d\n", i);
			break;
		}
	
    return 0;
}
