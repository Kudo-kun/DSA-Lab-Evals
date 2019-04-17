#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 55
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long

int cnt, n, k;
/******************************************************************/
typedef struct pairtype
{
	int freq;
	char s[N];
}Pair;


int check(char* str, Pair arr[])
{
	int flag = 0;
	for(int i = 0; i < cnt; i++)
		if(!strcmp(str, arr[i].s))
			flag = 1, arr[i].freq++;

	return flag;
}


int cmp(const void* a, const void* b)
{
	Pair x = (*(const Pair*)a), y = (*(const Pair*)b);
	return (x.freq < y.freq);
}
/******************************************************************/

int main()
{	
	scanf("%d\n", &n);
	Pair arr[n];
	for(int i = 0; i < n; i++)
	{
		char tmp[N];
		fgets(tmp, N, stdin);
		if(!i || !check(tmp, arr))
			strcpy(arr[cnt++].s, tmp), arr[cnt-1].freq = 1;
	}

	scanf("%d", &k);
	qsort(arr, cnt, sizeof(Pair), cmp);
	for(int i = 0; i < k; i++)
		printf("%s", arr[i].s);

	return 0;
}



       
       


