//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 26
#define MAX 1005

char s[MAX], p[MAX];
int n, f1[N], f2[N], ans;
/******************************************************************************/

/******************************************************************************/

int main()
{
    scanf("%s%s%d", s, p, &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", arr+i);
    
    for(int i = 0; i < strlen(p); i++)
        f2[p[i] - 97]++;

    for(int i = 0; i < strlen(s); i++)
        f1[s[i] - 97]++;

    for(int i = 0; i < n; i++)
    {
        int x = s[arr[i] - 1] - 97;
        if(!f2[x] || f1[x] > f2[x])
        {
            ans++;
            f1[x]--;
            printf("%c ",x+97);
        }
        else if(f1[x] <= f2[x])
            break;
    }

    printf("\n%d\n", ans);
    return 0;
}
