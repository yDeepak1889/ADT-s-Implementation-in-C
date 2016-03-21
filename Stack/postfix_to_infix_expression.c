#include<stdio.h>
#include<string.h>
void push(char stack [][100], char buffer2[], int *);
void pop(char stack [][100], char get[], int*);
int main(void)
{
	char stack [100][100];
	char post[100];	
	char buffer1[100];
	char buffer2[100];
	char copy[100];
	char oper[10] = {'*', '+', '-', '/',};
	int top;
	top = -1;
	
	scanf("%s", post);
	
	int i;
	int j;	
	int flag = 0;
	int len;
	for(i = 0; i < strlen(post); i++) {
		for(j = 0; j < 4; j++) {
			if(post[i] == oper[j]) {
				flag++;
				break;
			}
		}
		if(flag) {
			pop(stack,buffer1,&top);
			pop(stack,buffer2,&top);
			copy[0] = '(';		
			copy[1] = '\0';
			strcat(buffer1, ")");
			strcat(copy, buffer2);
			len = strlen(copy);
			copy[len++] = post[i];
			copy[len] = '\0';
			strcat(copy, buffer1);
			push(stack, copy, &top);
		} else {
			buffer1[0] = post[i];
			buffer1[1] ='\0';
			push(stack, buffer1, &top);
		}
		flag = 0;
	}
	printf("%s\n", stack[top]);
	return 0;
}

//push
void push(char stack[100][100], char buffer2[], int * top) 
{
	(*top) ++;
	strcpy(stack[*top], buffer2);
	//printf("success  %d\n",*top);
	return ;
}
void pop(char stack[100][100], char get[], int * top)
{
	if(*top == -1) {
		printf("underflow\n");		
		return ;
	} else {
		strcpy(get, stack[*top]);
		(*top)--;
	}
	return ;
}

