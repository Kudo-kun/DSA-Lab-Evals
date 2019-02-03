//Author: Kudo_kun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 26
#define MAX 1005

int k, arr[N], cnt;
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


void Traverse(Node** head)
{
    Node* pos = *head;
    while(pos -> next)
    {
        printf("%d ", pos -> data);
        pos = pos -> next;
    }
}
/******************************************************************************/

int main()
{
    Node* head = NULL, *tail = NULL;
    scanf("%d", &k);
    for(cnt = 1; cnt <= N; cnt++)
    {
        char x;
        scanf("%d%c", &arr[cnt], &x);
        if(x == '\n')
            break;
    }

    int sel[cnt+1];
    memset(sel, 0, cnt*sizeof(int));
    for(int i = 1; (i*k) <= cnt; i++)
    {
        sel[i*k] = 1;
        Push_back(arr[i*k], &head, &tail);
    }


    for(int i = cnt; i >= 0; i--)
        if(!sel[i])
            Push_back(arr[i], &head, &tail);
    
    Traverse(&head);
    return 0;
}
