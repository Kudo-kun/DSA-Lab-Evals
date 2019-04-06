#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define N 1005
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int Q;
int front, back = - 1;
int arr[N];
/******************************************************************/
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void sort(int lo, int hi)
{
	for(int i = lo; i <= hi; i++)
		for(int j = lo; j <= hi; j++)
			if(arr[j] < arr[i])
				swap(arr+i, arr+j);
}

int Pop_Diff()
{
	if(front == back)
		return -1;
	int diff = (arr[front] - arr[back]);
	front++, back--;
	return diff;
}

int CountHigh()
{
	if(front == back)
		return -1;
	int x = arr[front], cnt = 0, i = front;
	while(arr[i++] == x)
		cnt++;
	return cnt;
}

int CountLow()
{
	if(front == back)
		return -1;
	int x = arr[back], cnt = 0, i = back;
	while(arr[i--] == x)
		cnt++;
	return cnt;
}
/******************************************************************/

int main()
{
	scanf("%d", &Q);
	while(Q--)

	{
		char comm[N];
		memset(comm, '\0', N*sizeof(char));
		scanf("%s", comm);
		if(!strcmp(comm, "Push"))
		{
			scanf("%d", &arr[++back]);
			sort(front, back);
			printf("Insert %d :: successful\n", arr[back]);
		}
		else if(!strcmp(comm, "Diff"))
			printf("%d\n", Pop_Diff());
		else if(!strcmp(comm, "CountHigh"))
			printf("%d\n", CountHigh());
		else if(!strcmp(comm, "CountLow"))
			printf("%d\n", CountLow());

		for(int i = front; i <= back; i++)
			printf("%d ", arr[i]);
		printf("\n\n");
	}
	return 0;
}



       
       


