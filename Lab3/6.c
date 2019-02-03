//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 10

char s[N], of, ef, flist[26], count;
/******************************************************************************/

/******************************************************************************/

int main()
{
	scanf("%s", s);
    for(int i = 0; i < strlen(s); i++)
        flist[s[i] - 97]++;

    for(int i = 0; i < 26; i++)
        if(flist[i])
        {
            (flist[i] % 2) ? of++ : ef++;
            count++;
        }

    ((!of && ef == count) || (of == 1 && ef == count-1)) ? printf("YES\n") : printf("NO\n");
    return 0;
}
