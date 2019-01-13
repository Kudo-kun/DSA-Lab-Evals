//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int listType, k, len = 0;
/******************************************************************************/
typedef struct nodetype
{
    int data;
    struct nodetype* next, *prev;
} Node;


void Insert(int x, Node** head, Node** tail)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp -> data = x; tmp -> prev = NULL; tmp -> next = NULL;
    if(*head == NULL)
        *head = tmp;
    else
    {
        Node* lastNode = *tail;
        lastNode -> next = tmp;
        if(listType == 2)
            tmp -> prev = lastNode;
    }
    *tail = tmp; len++;
}


void MakeCircular(Node** head, Node** tail)
{
    Node* pos = *tail;
    pos -> next = *head;
}


void GetKthNode(int k, Node** head)
{
    Node* pos = *head;
    for(int i = 0; i < (len-k); i++, pos = pos -> next){}
    printf("%d\n", pos -> data);
}
/******************************************************************************/

int main()
{

    Node* head = NULL, *tail = NULL;
    scanf("%d", &listType);
    while(1)
    {
        int x; char ch;
        scanf("%d%c", &x, &ch);
        Insert(x, &head, &tail);
        if(ch == '\n')
        {
            if(listType == 3) MakeCircular(&head, &tail);
            break;
        }
    }

    scanf("%d", &k);
    (k > len && listType != 3) ? printf("k out of bounds!") : GetKthNode(k%len, &head);
    return 0;
}
