#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 55
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

char mag[N][N], note[N][N];
int n, m, arr[N];
/******************************************************************/
int check(int u)
{
	for(int i = 0; i < n; i++)
		if(!strcmp(note[u], mag[i]) && !arr[i])
		{
			arr[i] = 1;
			return 1;
		}
	return 0;
}
/******************************************************************/

int main()
{	
	scanf("%d%d\n", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", mag[i]);
	for(int i = 0; i < m; i++)
		scanf("%s", note[i]);
	for(int i = 0; i < m; i++)
		if(!check(i))
			return printf("NO\n"), 0;

	printf("YES\n");
	return 0;
}



       
       


