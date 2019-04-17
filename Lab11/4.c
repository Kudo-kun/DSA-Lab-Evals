#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define LL long long

int L[N], R[N], C[N];
int T, p, q, s, n, m;
const int mod = 1000000;
/******************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
	return;
}

void update(int l, int r, int c, int pro[])
{
	for(int i = l; i <= r; i++)
		pro[i] += c;
	return;
}
/******************************************************************/

int main()
{	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		int pro[n+1], max_pro = INT_MIN, idx;
		memset(pro, 0, (n+1)*sizeof(int));
		memset(L, 0, N*sizeof(int));
		memset(R, 0, N*sizeof(int));
		memset(C, 0, N*sizeof(int));
		scanf("%d%d%d%d%d%d", L+1, R+1, C+1, &p, &q, &s);
		for(int i = 1; i <= m; i++)
		{
			update(L[i], R[i], C[i], pro);
			L[i+1] = ((L[i]*p + R[i]) % n) + 1;
			R[i+1] = ((R[i]*q + L[i]) % n) + 1;
			C[i+1] = ((C[i]*s) % mod) + 1;
			if(L[i+1] > R[i+1])
				swap(L+i+1, R+i+1);
		}

		for(int i = 1; i <= n; i++)
			if(pro[i] > max_pro)
				max_pro = pro[i], idx = i;

		printf("%d %d\n", idx, max_pro);
	}
	return 0;
}



       
       


