#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct element {
	int size;
	int  * data;
}stack;
void create(stack *);
void push(stack *, int );
char pop(stack *);
void print(stack *);
int main(void) 
{
	stack s1;
	s1.size = -1;
	s1.data = NULL;
	
	create(&s1);
	char str[100];
	scanf("%s", str);
	int a;
	int b;
	int i;
	i = 0;
	while(str[i] != '\0') {
		if(str[i] == '*') {
			a=pop(&s1);
			b=pop(&s1);
			push(&s1, a*b);
		} else if(str[i] == '/') {
                        a=pop(&s1);
                        b=pop(&s1);
                        push(&s1, b/a);
                } else if(str[i] == '-') {
                        a=pop(&s1);
                        b=pop(&s1);
                        push(&s1, b-a);
                } else if(str[i] == '+') {
                        a=pop(&s1);
                        b=pop(&s1);
                        push(&s1, a+b);
                } else if(str[i] == '^') {
                        a=pop(&s1);
                        b=pop(&s1);
                        push(&s1, a^b);
                } else {
			push(&s1 , (int)(str[i] - '0'));
		}
		//print(&s1);
		//printf("\n");
		i++;
	}
	print(&s1);
        return 0;		
}
void create(stack * s1)
{
	s1->data = (int*)malloc(sizeof(int));

	return ;
}
void push(stack * s1, int  c)
{
	(s1->size)++;
	s1->data = (int*)realloc(s1->data, sizeof(int)*(s1->size+1));
	(s1->data)[s1->size] = c;
	return ;
}
char pop(stack * s1)
{
	return (s1->data)[(s1->size)--];
}
void print(stack * s1)
{
	int i;
	for(i = 0 ; i <= s1->size ; i++) {
		printf("%d",(s1->data)[i]);
	}
	return ;
}
