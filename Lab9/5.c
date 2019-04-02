#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 105
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int n, x;
char str[N], ans[N];
/******************************************************************/
typedef struct pairtype
{
	int idx, freq;
} Pair;


void setPairArr(Pair arr[26])
{
	for(int i = 0; i < 26; i++)
		arr[i].idx = i, arr[i].freq = 0;
}


int cmp(const void* a, const void* b)
{
	Pair x = (*(const Pair*)a), y = (*(const Pair*)b);
	return (x.freq < y.freq);
}


int check()
{
	for(int i = 0; i < strlen(ans)-1; i++)
		if(ans[i] == ans[i+1])
			return 0;

	return 1;
}
/******************************************************************/

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("outp.txt", "w", stdout);

	Pair arr[26];
	scanf("%s", str);
	setPairArr(arr);
	for(int i = 0; i < strlen(str); i++)
		(arr[str[i] - 'a'].freq)++;


	qsort(arr, 26, sizeof(Pair), cmp);
	while(arr[0].freq)
		for(int i = 0; i < 26 && arr[i].freq; i++)
			ans[x++] = ((arr[i].idx) + 'a'), (arr[i].freq)--;

	printf("%s\n", ans);
	((strlen(ans) == strlen(str)) && check()) ? printf("Possible\n") : printf("Not Possible\n");
	return 0;
}