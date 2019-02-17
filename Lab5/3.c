//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 1005
#define ll long long int

int q, u, v;
/******************************************************************************/
typedef struct nodetype
{
	int data;
	struct nodetype *next, *prev;
} Node;


void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


void sort(Node** head)
{
	Node* curr = *head;
	while(curr)
	{
		Node* sec = curr;
		while(sec)
		{
			if(curr -> data > sec -> data)
				swap(&(curr -> data), &(sec -> data));
			sec = sec -> next;
		}
		curr = curr -> next;
	}
}


Node* find(int op, int k, Node** head, Node** tail)
{
	Node* pos = *head;
	while(pos)
	{
		if((pos -> data == k && op == 1) || (pos -> data > k && op == 2))
			return pos;
		pos = pos -> next;
	}
	return (*tail);
}


void FormList(int x, Node** head, Node** tail)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp -> data = x;
	tmp -> next = NULL;
	tmp -> prev = NULL;
	if (*head)
	{
		tmp -> prev = (*tail);
		(*tail) -> next = tmp;
	}
	else
		*head = tmp;
	*tail = tmp;
}


void Insert(int k, Node* loc, Node** head, Node** tail)
{
	printf("...%d...\n", loc -> data);
	if((*tail) -> data < k)
	{
		FormList(k, head, tail);
		return;
	}
	
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp -> data = k;
	tmp -> next = NULL;
	tmp -> prev = NULL;
	if(loc == *head)
	{
		tmp -> next = *head;
		*head = tmp;
	}
	else
	{
		tmp -> next = loc;
		tmp -> prev = loc -> prev;
		loc -> prev = tmp;
		(tmp -> prev) -> next = tmp;
	}
}


void Delete(Node* loc, Node** head, Node** tail)
{
	if(loc == *head)
		*head = loc -> next;
	else if(loc == *tail)
	{
		*tail = loc -> prev;
		(*tail) -> next = NULL;
	}
	else
	{
		Node* Prev = loc -> prev, *Post = loc -> next;
		Prev -> next = Post;
		Post -> prev = Prev;
	}
	free(loc);
}


void PrintList(Node** head)
{
	Node* pos = *head;
	while(pos)
	{
		printf("%d ", pos -> data);
		pos = pos -> next;
	}
	printf("\n");
}
/******************************************************************************/

int main()
{
	Node* head = NULL, *tail = NULL;
	for(int i = 0, x; i > -1; i++)
	{
		char ch;
		scanf("%d%c", &x, &ch);
		FormList(x, &head, &tail);
		if(ch == '\n')
			break;
	}

	scanf("%d", &q);
	while(q--)
	{
		char s[3];
		memset(s, '\0', 3*sizeof(char));
		scanf("%s", s);
		if(!strcmp(s, "I"))
		{
			scanf("%d", &u);
			Insert(u, find(2, u, &head, &tail), &head, &tail);
		}
		else if(!strcmp(s, "D"))
		{
			scanf("%d", &u);
			Delete(find(1, u, &head, &tail), &head, &tail);
		}
		else if(!strcmp(s, "SW"))
		{
			scanf("%d%d", &u, &v);
			Node* a = find(1, u, &head, &tail), *b = find(1, v, &head, &tail);
			swap(&(a -> data), &(b -> data));
		}
		else if(!strcmp(s, "SO"))
			sort(&head);
		
		PrintList(&head);
	}
	return 0;
}
