//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 50

int n;
typedef struct nodetype
{
    int data;
    struct nodetype* next;
} Node;

/******************************************************************************/
void swapData(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


Node* getPrev(Node* pos, Node** head)
{
    Node* prev = *head;
    while(prev -> next != pos)
        prev = prev -> next;

    return prev;
}


void Push_Back(int x, Node** head, Node** tail)
{
    Node* tmp = (Node*)(malloc(sizeof(Node)));
    tmp -> data = x; tmp -> next = NULL;
    if(*head == NULL)
        *head = tmp;
    else
    {
        Node* lastNode = *tail;
        lastNode -> next = tmp;
    }
    *tail = tmp;
}


int Search(int x, Node** head)
{
    Node* pos = *head;
    int cnt = 0;
    while(pos && ++cnt)
    {
        if(pos -> data == x)
            return cnt;

        pos = pos -> next;
    }
    return -1;
}


void Delete(int x, Node** head)
{
    int flag = 0;
    Node* pos = *head;
    while(pos)
    {
        if(pos -> data == x && !flag)
            flag = 1;
        else if(pos -> data == x && flag)
        {
            Node* prev = getPrev(pos, head);
            prev -> next = pos -> next;
            free(pos); pos = prev;
        }
        pos = pos -> next;
    }
    return;
}


void Swap(int x, Node** head)
{
    Node* pos = *head;
    while(pos)
    {
        if(pos -> data == x)
        {
            swapData(&(pos -> data), &((pos -> next) -> data));
            return;
        }
        pos = pos -> next;
    }
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
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        {int t; scanf("%d", &t); Push_Back(t, &head);}

    PrintList(&head);
    int k; scanf("%d", &k);
    printf("%d\n", Search(k, &head));
    Delete(k, &head);
    PrintList(&head);

    Swap(k, &head);
    PrintList(&head);
    return 0;
}
