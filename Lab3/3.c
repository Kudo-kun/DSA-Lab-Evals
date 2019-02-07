//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 26
#define MAX 1005

int k;
/******************************************************************************/
typedef struct nodetype
{
    int data;
    struct nodetype* next;
} Node;


void Push_back(int x, Node** head, Node** tail)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp -> data = x; tmp -> next = NULL;

    (*head == NULL) ? (*head = tmp) : ((*tail) -> next = tmp);
    *tail = tmp;
}

void Emplace_front(int x, Node** head)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp -> data = x; tmp -> next = NULL;
    if(*head)
        tmp -> next = *head;
       
     *head = tmp;
}


void Traverse(Node** head1, Node** head2, Node** tail1)
{
    (*tail1) -> next = *head2;
    Node* pos = *head1;
    while(pos)
    {
        printf("%d ", pos -> data);
        pos = pos -> next;
    }
}
/******************************************************************************/

int main()
{
    Node* head1 = NULL, *head2 = NULL, *tail1 = NULL;
    scanf("%d", &k);
    for(int i = 1, x; i <= N; i++)
    {
        char ch;
        scanf("%d%c", &x, &ch);
        (i%k) ? Emplace_front(x, &head2) : Push_back(x, &head1, &tail1);
    
        if(ch == '\n')
            break;
    }

    Traverse(&head1, &head2, &tail1);
    return 0;
}
