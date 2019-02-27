//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105
#define ll long long int

int n, flag;
char str[N], ans[N];
/******************************************************************************/
int isPalindrome(int i, int L, char str[])
{
	for(int j = 0; j < L; j++)
		if(str[j+i] != str[L-j+i-1])
			return 0;

	return 1;
}


int isSorted(int i, int L, char str[])
{
	for(int j = i; j < (i+(L/2)); j++)
		if(str[j] > str[j+1])
			return 0;

	return 1;

}


int cmp(int i, int L, char str[], char ans[])
{
	for(int j = 0; j <= L; j++)
		if(ans[j+i] > str[j] || ans[0] == '\0')
			return 1;

	return 0;
}


void copy(int i, int L, char str[])
{
	for(int j = 0; j < L; j++)
		ans[j] = str[i+j];
}
/******************************************************************************/

int main()
{
	scanf("%s", str);
	int L = (strlen(str) & 1) ? (strlen(str) - 1) : strlen(str);

	for(; L > 2 && !flag; L--)
		for(int i = 0; (i+L) <= strlen(str); i++)
			if(isPalindrome(i, L, str) && isSorted(i, L, str) && cmp(i, L, str, ans))
				flag = 1, memset(ans, '\0', N*sizeof(char)), copy(i, L, str);
			
	(ans[0] == '\0') ? printf("-1\n") : printf("%s\n", ans);
	return 0;
}
