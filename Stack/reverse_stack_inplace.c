#include<stdio.h>
#include<stdlib.h>
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
void reverse(stack *);
void insert_buttom(stack *, int);

int main(void)
{
	stack s;
	s.top=-1;
	s.items=(int*)malloc(sizeof(int));
	int test;
	int end;
	int x;
	end = 1;
	printf("1.push\n2.pop\n3.print\n4.end\n");
	while(end) {
		scanf("%d", &test);
		switch(test) {
			case 1:
				scanf("%d", &x);
				push(&s, x);
				break;
			case 2:
				x = pop(&s);
				break;
			case 3:
				print(&s);
				break;
			case 4:
				end = 0;
				break;
		}
	}
	reverse(&s);
	print(&s);		
	
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
//reverse
void reverse(stack * s)
{
	if(s->top == -1) {
		return ;
	}
	int x;
	x = pop(s);	
	reverse(s);
	
	insert_buttom(s, x);
}
//insert buttom
void insert_buttom(stack * s, int x)
{	
	if(s->top == -1) {
		push(s, x); 
		return ;
	}
	int temp;
	temp =pop(s);
	insert_buttom(s, x);
	
	push(s, temp);
}
	
