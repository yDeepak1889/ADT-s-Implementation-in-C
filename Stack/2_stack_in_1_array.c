#include<stdio.h>

void push1(int *, int , int *);
int pop1(int *, int *);
void push2(int *, int, int *);
int pop2(int *, int *);
void print1(int *, int *);
void print2(int* , int *);
int  is_full(int *, int *, int *);

int main(void)
{
	int arr[100];
	int l1;
	int l2;
	int test;
	int end;
	int x;
	
	l1 = -1;
	l2 = 100;
	end = 1;
	
	printf("1.push1\n2.push2\n3.pop1\n4.pop2\n5.print1\n6.print2\n7.end\n");
	while(end) {
		scanf("%d", &test);
		switch(test) {
			case 1:
				scanf("%d", &x);
				push1(arr, x, &l1);
				break;
			case 2:
				scanf("%d", &x);
				push2(arr + 99, x, &l2);
				break;
			case 3:
				x = pop1(arr , &l1);
				printf("%d\n", x);
				break;
			case 4:
				x = pop2(arr + 99, &l2);
				printf("%d\n", x);
				break;
			case 5:
				print1(arr, &l1);
				break;
			case 6:
				print2(arr + 99, &l2);
				break;
			case 7:
				end = 0;
		}
	}
	return 0;
}
///////////////////////////////////////	
void push1(int * stack , int x, int *l1)
{
	stack[++*l1] = x;
	return ;
}
void push2(int * stack, int x, int *l2)
{
	stack[--*l2] = x;
	return ;
}
int pop1(int * stack , int *l1)
{
	return stack[(*l1)--];
}
int pop2(int * stack, int * l2)
{
	return stack[(*l2)++];
}
void print1(int * stack ,int * l1)
{	
	int i;
	for(i = *l1 ; i >= 0; i--) {
		printf("%d ", stack[i]);
	}
}
void print2(int * stack , int * l2)
{
	int i;
	for(i = *l2 ; i < 100 ; i++) {
		printf("%d ", stack[i]);
	}
	return ;
}
int  is_full(int * stack, int * l1, int * l2)
{
	if(l2 - l1 ==1) {
		return 1;
	}
	return 0;
}
