//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


/******************************************************************************/
void SieveOfErato(int a, int b)
{
    int tmp[b];
    for(int i = 2; i <= sqrt(b); i++)
        for(int j = 2; i*j <= b; j++)
            tmp[i*j] = 1;

    for(int i = a; i < b; i++)
        if(!tmp[i])
            printf("%d ", i);

    printf("\n"); 
}
/******************************************************************************/

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    SieveOfErato(a, b);
    return 0;
}
