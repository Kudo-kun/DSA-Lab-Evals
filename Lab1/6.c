//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


/******************************************************************************/
void SieveOfErato(int a, int b, int arr[])
{
    int* tmp = (int*)calloc(b, sizeof(int));
    for(int i = 2; i <= sqrt(b); i++)
        for(int j = 2; i*j <= b; j++)
            tmp[i*j] = 1;

    for(int i = a; i < b; i++)
        if(!tmp[i])
            printf("%d ", i);

    printf("\n"); free(tmp);
}
/******************************************************************************/

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ans[b];
    SieveOfErato(a, b, ans);
    return 0;
}
