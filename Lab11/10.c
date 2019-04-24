#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define null -999
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long

int n;
char str[N][N];
/***************************************************************************************************************************/
int isEqual(char* s1, char* s2)
{
	for(int i = 0; i < strlen(s1); i++)
		if(s1[i] != s2[i])
			return 0;

	return 1;
}


void func(int i, char* s)
{
	int cnt = 0, sig = 0;
	while(cnt <= strlen(str[i]))
	{
		sig = 0, s[strlen(s)] = str[i][cnt++];
		for(int j = 0; j < n; j++)
			if(i != j)
				if(isEqual(s, str[j]))
				{
					sig = 1;
					break;
				}
		
		if(!sig)
		{
			printf("%s\n", s);
			return;
		}
	}
}
/***************************************************************************************************************************/

int main()
{	
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", str[i]);
	for(int i = 0; i < n; i++)
	{
		char s[N];
		memset(s, 0, N*sizeof(char));
		func(i, s);
	}

	return 0;
}



       
       


