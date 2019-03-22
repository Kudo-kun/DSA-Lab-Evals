//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define ll long int
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int n, k, fin_ans;
char s[N], LUT[] = "RYG";
/******************************************************************************/
int find(char ch)
{
	for(int i = 0; i < 3; i++)
		if(LUT[i] == ch)
			return i;
}


int update(int j, int m, int offset)
{
	for(; j <= m; j++)
		s[j] = LUT[(find(s[j]) + offset) % 3];
}
/******************************************************************************/

int main()
{
	scanf("%d%d\n%s", &n, &k, s);
	printf("received string is : %s\n", s);
	
	int i = 0;	
	while(i < (n-1))
	{
		int m = min(n-1, i+k-1), j = i;
		for(; j <= m; j++)
		{
			int offset = (2 - find(s[j]));
			update(j, m, offset);
			fin_ans += offset;
		}
		
		i = j;
	}

	printf("Number of operations is: %d\n", fin_ans);
	return 0;
}


