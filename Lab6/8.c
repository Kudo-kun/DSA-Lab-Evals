//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105
#define ll long long int


int n, m, q, FLAG;
char grid[N][N];

/******************************************************************************/
int Find(int x, int y, int i, char s[])
{
	int val = 0;
	if(i == strlen(s)-1 && s[i] == grid[x][y])
		return 1;
	if(grid[x-1][y] == s[i+1] && x >= 1 && !val && i < strlen(s))
		val += Find(x-1, y, i+1, s); 
	if(grid[x][y+1] == s[i+1] && !val && i < strlen(s))
		val += Find(x, y+1, i+1, s); 
	if(grid[x+1][y] == s[i+1] && !val && i < strlen(s))
		val += Find(x+1, y, i+1, s); 
	if(grid[x][y-1] == s[i+1] && y >= 1 && !val && i < strlen(s))
		val += Find(x, y-1, i+1, s); 
	return val;
}
/******************************************************************************/

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", grid[i]);

	scanf("%d", &q);
	while(q--)
	{
		FLAG = 0;
		char* str = calloc(N, sizeof(char));
		scanf("%s", str);
		for(int i = 0; i < n && !FLAG; i++)
			for(int j = 0; j < m && !FLAG; j++)
				if(grid[i][j] == str[0] && Find(i, j, 0, str))
					FLAG = 1;

		(FLAG == 1) ? printf("Yes\n") : printf("No\n");
		free(str);
	}
	return 0;
}
