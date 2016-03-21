#include<stdio.h>
#include<string.h>

void push(char stack [100][100], char get[], int * top)
{
	(*top)++;
	strcpy(stack[*top], get);
	return ;
}

void pop(char stack[100][100], char get[], int * top)
{
	if (*top == -1) {
		printf("underflow\n");
		return ;
	}
	else {
	strcpy(get, stack[*top]);
	(*top)--;
	return ;
	}
}
int main(void)
{	
	char stack[100][100];
	char pre[100];
	char buffer1[100];
	char buffer2[100];
	char copy[100];
	int top;
	char original[100];
	top = -1;
	char op[10] = {'+', '-', '/', '*', '%'};
	
	int i;
	int j;
	int flag;	
	int len;
	flag = 0;
	
	scanf("%s", pre);
	
	for(i = strlen(pre) - 1; i >= 0; i--) {
		for(j = 0; j < 5; j++) {
			if( pre[i] == op[j]) {	
				flag ++;
				break;
			}
		}
		if (flag) {
			pop(stack, buffer1, &top);
			pop(stack, buffer2, &top);
			
			copy[0] = '(';
			copy[1] = '\0';
			
			strcat(copy, buffer2);
			len = strlen(copy);
			copy[len++] = pre[i];
			copy[len] = '\0';
			
			strcat(buffer1, ")");
			
			strcat(copy, buffer1);
			push(stack, copy, &top);
		}
		else {
			buffer1[0] = pre[i];
			buffer1[1] = '\0';
			push(stack, buffer1, &top);
		}
		flag = 0;
	}
	
	
	for (i = strlen(stack[top])-1 ,j = 0; i >= 0; i--, j++) {
		if(stack[top][i] == ')') {
			original[j] = '(';
		} else if (stack[top][i] == '(') {
			original[j] = ')';
		} else {
			original[j] = stack[top][i];
		}
	}
	original[i] = '\0';
	printf("%s\n",original);
	
	
	return 0;
}
		
