//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int cnt1, cnt2, op;
char s[N], encode[N], decode[N];

/******************************************************************************/
void CopyStr(int curr, int prev, char ans[])
{
    for(int i = curr-1; i >= prev; i--)
        ans[cnt1++] = s[i];

    ans[cnt1++] = ' ';
}

void reverseWords(char ans[])
{
    for(int i = 0, prev = 0; i < strlen(s); i++)
        if(s[i] == ' ')
            {CopyStr(i, prev, ans); prev = i+1;}
}
/******************************************************************************/



int main()
{
    scanf("%d\n", &op);
    scanf("%[^\n]", s); s[strlen(s)] = ' ';

    if(op == 0)
    {
        for(int i = 0, k = 0; i < strlen(s); i++)
        {
            if(s[i] != ' ' && (i-k)%2 == 0)
                s[i] = ((s[i] - 94) % 26) + 97;
            else if(s[i] == ' ')
                k++;
        }
        reverseWords(encode);
        printf("%s\n", encode);
    }
    else
    {
        reverseWords(decode);
        for(int i = 0, k = 0; i < strlen(decode); i++)
        {
            if(decode[i] != ' ' && (i-k)%2 == 0)
                decode[i] = ((decode[i] - 74) % 26) + 97;
            else if(decode[i] == ' ')
                k++;
        }
        printf("%s\n", decode);
    }

    return 0;
}
