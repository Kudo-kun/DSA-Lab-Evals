//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 105
#define ll long long int


int n, m;
/******************************************************************************/
typedef struct nodetype
{
	int data;
	struct nodetype* next;
} Node;


void Push_Back(int x, Node** head, Node** tail)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp -> next = NULL;
	tmp -> data = x;
	(*head == NULL) ? (*head = tmp) : ((*tail) -> next = tmp);
	*tail = tmp;
}


void Pop_Front(Node** head)
{
	Node* pos = *head;
	*head = (*head) -> next;
	free(pos);
}


void Merge(Node** head1, Node** head2, Node** head3, Node** tail3)
{
	while(*head1 && *head2)
	{
		Node* prim = *head1, *sec = *head2;
		if((prim -> data) > (sec -> data))
		{
			Push_Back(sec -> data, head3, tail3);
			Pop_Front(head2);
		}
		else
		{
			Push_Back(prim -> data, head3, tail3);
			Pop_Front(head1); 
		}
	}

	while(*head1)
	{
		Node* pos = *head1;
		Push_Back(pos -> data, head3, tail3);
		Pop_Front(head1);
	}
	while(*head2)
	{
		Node* pos = *head2;
		Push_Back(pos -> data, head3, tail3);
		Pop_Front(head2);
	}
}


void PrintList(Node** head)
{
	Node* curr = *head;
	while(curr)
	{
		printf("%d ", curr -> data);
		curr = curr -> next;
	}
	printf("\n");
}
/******************************************************************************/

int main()
{
	Node* head[3], *tail[3];
	head[1] = head[2] = head[3] = tail[0] = tail[1] = tail[2] = NULL;

	scanf("%d", &n);
	for(int i = 0, t; i < n; i++)
	{
		scanf("%d", &t);
		Push_Back(t, &head[0], &tail[0]);
	}

	scanf("%d", &m);
	for(int i = 0, t; i < m; i++)
	{
		scanf("%d", &t);
		Push_Back(t, &head[1], &tail[1]);
	}

	Merge(&head[0], &head[1], &head[2], &tail[2]);
	PrintList(&head[2]);
	return 0;
}
