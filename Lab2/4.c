//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50


int n, t, count, len;
/******************************************************************************/
typedef struct nodetype
{	
	int id, col;
	struct nodetype *next, *prev;
} Node;


Node* getIthNode(int loc, Node** head)
{
	Node* pos = *head;
	while(pos -> id != loc)
		pos  = pos -> next;

	return pos;
}


void Push_Back(int x, int y, Node** head, Node** tail)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp -> id = x; tmp -> next = NULL; tmp -> prev = NULL; tmp -> col = -999;

	if(*head == NULL)
		*head = tmp;
	else
	{
		(*tail) -> next = tmp;
		if(y != 0)
			tmp -> prev = getIthNode(y, head);
	}
	*tail = tmp; len++;
}


void PrintCycles(int i, Node** head)
{
	Node* pos = getIthNode(i, head);
	int fin  = (pos -> id);
	if(pos -> prev -> id < (fin-1))
	{
		printf("%d ", fin);
		pos = pos -> prev; count++;
		
		while(pos -> id != fin)
		{
			printf("%d ", pos -> id);
			pos = pos -> next;
		}
		printf("%d\n", fin);
	}
}


void getColourSequence(Node** head)
{
	Node* pos = *head; 
	pos -> col = 1; pos = pos -> next;
	int prevCol = 1;

	while(pos)
	{
		int colors[6]; memset(colors, 0, 6*sizeof(int)); 
		colors[((pos -> prev) -> col)] = 1; colors[prevCol] = 1;

		for(int i = 1; i < 6; i++)
			if(colors[i] == 0)
				{pos -> col = i; break;}

		prevCol = pos -> col;
		pos = pos -> next; 	
	}

	pos = *head;
	while(pos)
	{
		printf("%c", (pos -> col) + 64);
		pos = pos -> next;
	}

	printf("\n");
}
/******************************************************************************/

int main()
{   
	Node* head = NULL, *tail = NULL;
	int x, y, z; char ch;
	while(scanf("%d%d%d%c", &x, &y, &z, &ch))
	{
		Push_Back(x, y, &head, &tail); 
		if(ch == '\n')
			break;
	}

	printf("\nCycles in the list are:\n");
	for(int i = 2; i <= len; i++) 
		PrintCycles(i, &head);
	
	printf("\nNumber of cycles in the given list are: %d, and color scheme is: ", count);
	getColourSequence(&head);
    return 0;
}
