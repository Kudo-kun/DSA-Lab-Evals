#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 26
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int n, ans;
char ch;
/******************************************************************/
int check(int j, int L, int arr[])
{
	int x = 0, y = 0;
	for(int i = 0; i < L; i++)
		(arr[i + j]) ? (x++) : (y++);
	return (x == y); 
}
/******************************************************************/

int main()
{
	int arr[N];
	scanf("%c", &ch);
	while(1)
	{
		scanf("%d%c", &arr[n], &ch), n++;
		if(ch == '}')
			break;
	}
	for(int i = 0; i < n; i++)
		for(int L = 2; i+L <= n; L += 2)
			if(check(i, L, arr))
				ans++;

	printf("No. of such subarrays are: %d\n", ans);
	return 0;
}



       
       


