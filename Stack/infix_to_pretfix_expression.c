#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
	int top;
	int *items;
}stack;
void push(stack * , int );
int print(stack * );
int isempty(stack*);
int top_ele(stack*);
int pop(stack*);
int main(void)
{
	stack s;
	s.top=-1;
	s.items=(int*)malloc(sizeof(int));
	
	char str[100];
	char pre[100];
	scanf("%s", str);
	
	int i;
	int k = 0;
	
	for(i = strlen(str)-1; i >= 0; i--) {
		switch(str[i]) {
			case ')':
				push(&s, ')');
				break;
			case '/':
			case '*':
				push(&s, str[i]);
				break;
			case '+':
			case '-':
				while(top_ele(&s) == '*' | top_ele(&s) == '/') {
					pre[k++] = pop(&s);
				}
				push(&s, str[i]);
				break;
			case '(':
				while(top_ele(&s) != ')') {
					pre[k++] = pop(&s);
				}
				pop(&s);
				break;
			default :
				pre[k++]  = str[i];
		}
	}
	
	pre[k] = '\0';
	for(i = strlen(pre) -1; i >= 0; i--) 
		printf("%c", pre[i]);
		printf("\n");
	return 0;
}


//push
void push(stack * s, int x)
{
	(s->top)++;
	s->items=(int*)realloc(s->items,sizeof(int)*(s->top+1));
	(s->items)[s->top]=x;

	return ;
}

//print
int print(stack * s)
{
	if(isempty(s)==-1)
		return -1;
	else
	{
		int i=0;
		for(i=0;i<=s->top;i++)
			printf("%d  ",(s->items)[i]);
			printf("\n");
		return 0;
	}
}

//isempty
int isempty(stack * s)
{
	if(s->top==-1)
		return -1;
	else
		return s->top;
}
//pop
int pop(stack * s )
{
	if(isempty(s)==-1)
		return -1;
	else
		return (s->items)[s->top--];
}
//top_ele
int top_ele(stack * s)
{
	if(isempty(s)==-1)
		return -1;
	else
		return (s->items)[s->top];
}
