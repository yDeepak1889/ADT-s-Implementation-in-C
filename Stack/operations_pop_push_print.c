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
int main(void)
{
	stack s;
	s.top=-1;
	s.items=(int*)malloc(sizeof(int));
	printf("1. push x \n2.pop \n3.isempty\n4.top element\n5.print stack\n6.end\n");
	
	int test,end=1;
	int x,top,empty, a,ans;
	while(end)
	{
		scanf("%d",&test);
		switch(test)
		{
			case 1:
				
				printf("enter element to be pushed \n");
				scanf("%d",&x);
				push(&s, x);
				break;
			case 2:
				
					a=pop(&s);
					if(a==-1)
						printf("underflow\n");
					else
						printf("poped element is %d\n",a);
					break;
			case 3:
				
					empty=isempty(&s);
				if(empty==-1)
					printf("stack is empty\n");
				else
					printf("stack is not empty\n");
				break;
			case 4:
				
					top=top_ele(&s);
					if(top==-1)
						printf("underflow\n");
					else
						printf("top element is %d \n",top);
				break;
			case 5:
				ans=print(&s);
				if(ans==-1)
					printf("empty stack\n");
				break;
			
			case 6:
				end=0;
				break;
		}
	}
	
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
