//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 26
#define MAX 1005

char s[MAX];
int T;
/******************************************************************************/
void RotateSubstr(int f, int r, int k, char s[])
{
    while(k--)
    {
        char front = s[f];
        for(int i = f; i <= r; i++)
            s[i] = s[i+1];

        s[r] = front;
    }
}

/******************************************************************************/

int main()
{
    scanf("%s%d", s, &T);
    while(T--)
    {
        int f, r, k;
        scanf("%d%d%d", &f, &r, &k);
        k %= strlen(s);
        RotateSubstr(--f, --r, k, s);
    }
    
    printf("%s\n", s);
    return 0;
}
