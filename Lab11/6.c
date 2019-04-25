#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include<ctype.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long
 
int n, q;
char str[N][N];
/***************************************************************************************************************************/
int isVowel(char c)
{
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	return 0;
}



int checkEqual(char* s)
{
	for(int i = 0; i < n; i++)
		if(!strcmp(s, str[i]))
			return 1;
 
	return 0;
}
 
 
int checkCap(char* s)
{
	for(int i = 0; i < n; i++)
		if(strlen(s) == strlen(str[i]))
		{
			int flag = 0;
			for(int j = 0; j < strlen(s); j++)
				if(s[j] != str[i][j] && tolower(s[j]) != tolower(str[i][j]))
				{
					flag = 1;
					break;
				}
			if(!flag)
				return i;
		}
	return -1;			
}
 
 
int checkVow(char* s)
{
	for(int i = 0; i < n; i++)
		if(strlen(s) == strlen(str[i]))
		{
			int flag = 0;
			for(int j = 0; j < n; j++)
				if(!(s[j] == str[i][j] || tolower(s[j] == tolower(str[i][j]) || (isVowel(tolower(s[j])) && isVowel(tolower(str[i][j]))))))
				{
					flag = 1;
					break;
				}
			if(!flag)
				return i;
		}
	return -1;
}
 
 
/***************************************************************************************************************************/
 
int main()
{	
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", str[i]);
	scanf("%d", &q);
	while(q--)
	{
		char s[N];
		scanf("%s", s);
		if(checkEqual(s))
			printf("%s\n", s);	
		else if(checkCap(s) != -1)
			printf("%s\n", str[checkCap(s)]);
		else if(checkVow(s) != -1)
			printf("%s\n", str[checkVow(s)]);
		else
			printf("-------------\n");
	}
	return 0;
}