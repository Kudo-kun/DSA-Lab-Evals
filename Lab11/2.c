#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 55
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

char mag[N], note[N];
int n, m, cnt1, cnt2;
char words1[N][N], words2[N][N];
/******************************************************************/
void getWords(char* s, char X[N][N], int* cnt)
{
	int lo = 0, hi = 0;
	while(lo < (strlen(s)-1))
	{
		while(hi < (strlen(s)-1) && s[hi] != ' ')
			hi++;
		printf("hello :: %d %d\n", lo, hi);
		for(int j = lo; j < hi; j++)
			X[*cnt][j-lo] = s[j];
		
		(*cnt)++;
		lo = ++hi;
	}
}

int check(char* s)
{
	for(int i = 0; i < n; i++)
		if(!strcmp(s, words1[i]))
		{
			printf("found at :: %d\n", i);
			return 1;
		}

	return -1;
}
/******************************************************************/

int main()
{	
	scanf("%d%d\n", &n, &m);
	fgets(mag, N, stdin);
	fgets(note, N, stdin);
	
	getWords(mag, words1, &cnt1);
	getWords(note, words2, &cnt2);
	if(m > n)
		return printf("NO\n"), 0;
	for(int i = 0; i < m; i++)
		if(check(words2[i]) == -1)
			return printf("NO\n"), 0;

	printf("YES\n");
	return 0;
}



       
       


