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


int n, glb_min = INT_MAX;
/******************************************************************************/
typedef struct stacktype
{
	int top;
	int arr[N];
}Stack;

void Push(int x, Stack* xyz)
{
	xyz -> arr[++(xyz -> top)] = x;
}

int Peek(Stack* xyz)
{
	return xyz -> arr[xyz -> top];
}

int Pop(Stack* xyz)
{
	int val = xyz -> arr[xyz -> top];
	(xyz -> top)--;
	return val;
}
/******************************************************************************/

int main()
{
	Stack* stk = malloc(sizeof(Stack)); 	(stk -> top) = -1;
	Stack* min_stk = malloc(sizeof(Stack)); (min_stk -> top) = -1;
	while(1)
	{
		char comm[N];
		memset(comm, '\0', sizeof(char));
		printf("Enter operation: ");
		scanf("%s", comm);
		if(!strcmp(comm, "push"))
		{
			int tmp;
			scanf("%d", &tmp);
			printf("Enter the element :");
			Push(tmp, stk);
			if(tmp < glb_min)
				glb_min = tmp, Push(glb_min, min_stk);
			printf("new element (%d) pushed into stack successfully\n", tmp);
		}
		else if(!strcmp(comm, "pop"))
		{
			if(Peek(stk) == Peek(min_stk))
				Pop(min_stk);
			printf("popped element is: %d\n", Pop(stk));
		}
		else if(!strcmp(comm, "min"))
			printf("min_element is: %d\n", Peek(min_stk));
		else if(!strcmp(comm, "end"))
			break;
	}
	return 0;
}


