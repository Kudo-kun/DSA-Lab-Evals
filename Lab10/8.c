#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)


int n, Q, k;
int seats[N];
char pref[N];
/******************************************************************/
typedef struct pairtype
{
	int lo, len, hi;
} Pair;


Pair find()
{
	Pair ans;
	ans.lo = 0;
	ans.len = INT_MIN;
	int i = 0;
	while(i < n)
	{
		if(seats[i] == -1)
		{
			int j = i, L = 0;
			while(j < n && seats[j] == -1 && i < n)
				j++, L++;
			if(L > ans.len)
				ans.len = L, ans.lo = i;
			i = j;
		}
		else
			i++;
	}
	ans.hi = (ans.lo + ans.len - 1);
	return ans;
}
/******************************************************************/

int main()
{
	scanf("%d%d%s", &n, &k, pref);
	memset(seats, -1, N*sizeof(int));
	for(int i = 0, pos; i < k; i++)
	{
		Pair op = find();
		printf("%d %d %d || ", op.lo, op.len, op.hi);
		int pos = ((op.lo + op.hi)/2);
		if(!(op.len & 1))
			pos += (pref[i] == 'R');

		seats[pos] = (i+1);
	}

	scanf("%d", &Q);
	while(Q--)
	{
		int u;
		scanf("%d", &u);
		printf("%d ", seats[u-1]);
	}
	return 0;
}



       
       


