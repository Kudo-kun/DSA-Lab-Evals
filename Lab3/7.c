//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005

char s[N];
/******************************************************************************/

/******************************************************************************/

int main()
{
    scanf("%s", s);
	for(int i = 0; i < strlen(s); i++)
        printf("%c", (((s[i] - 94) % 26) + 97));
    
    return 0;
}
