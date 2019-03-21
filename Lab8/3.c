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


int n;
char stk[N], s[N];
/******************************************************************************/
void Push(char ch)
{
	stk[strlen(stk)] = ch;
}

void Pop()
{
	stk[strlen(stk) - 1] = '\0';
}

char Peek()
{
	return stk[strlen(stk) - 1];
}
/******************************************************************************/

int main()
{
	scanf("%s", s);
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			Push(s[i]);
		else if((s[i] == ')' && Peek() != '(') || (s[i] == '}' && Peek() != '{') || (s[i] == ']' && Peek() != '['))
			return printf("FALSE\n"), 0;
		else
			Pop();
	}

	(!strlen(stk)) ? printf("TRUE\n") : printf("FALSE\n");
	return 0;
}


