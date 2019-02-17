//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 107
#define ll long long int

int a, b, c, q, xb[N], ps[N], ans, cost;
int n1, n2;
/******************************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


void sort(int n, int arr[])
{
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if(arr[j] < arr[i])
				swap(arr+i, arr+j);
}
/******************************************************************************/

int main()
{

	scanf("%d%d%d%d", &a, &b, &c, &q);
	for(int i = 0, x; i < q; i++)
	{
		char s[5];
		memset(s, '\0', 4*sizeof(char));
		scanf("%d %s", &x, s);
		((s[0] == 'X') ? (xb[n1++] = x) : (ps[n2++] = x));
	}

	sort(n1, xb); 
	sort(n2, ps);

	int j1 = 0, j2 = 0;
	for(int i = 0; i < a && j2 < n2; i++, ans++)
		cost += ps[j2++];
	for(int i = 0; i < b && j1 < n1; i++, ans++)
		cost += xb[j1++];
	
	for(int i = 0; i < c; i++)
	{
		if((j1 < n1 && j2 < n2 && xb[j1] <= ps[j2]) || (j1 < n1 && j2 >= n2))
		{
			cost += xb[j1++];
			ans++;
		}
		else if((j1 < n1 && j2 < n2 && xb[j1] > ps[j2]) || (j1 >= n1 && j2 < n2))
		{
			cost += ps[j2++];
			ans++;
		}
	}

	printf("\n%d %d\n", ans, cost);
	return 0;
}
