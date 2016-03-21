#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
	int capacity;
	int top;
	int * arr;
}stack;

stack * create(int capacity)
{
	stack * new = (stack*)malloc(sizeof(stack));
	new ->capacity = capacity;
	new -> top = -1;
	new -> arr = (int*)malloc(sizeof(int) * new ->capacity);
	//printf("success 1\n");
	return new;
}
void push(stack * s, int item)
{
	(s->top) ++;
	
	(s->arr)[s->top] = item;
	return ;
}
int pop(stack * s)
{
	if(s->top == -1)
		return -1;
	return s->arr[s->top--];
}
void t_o_h(int num_disks, stack * src, stack * aux, stack * des)
{
	int i;
	int total;
	
	char s,a,d;
	s = 'S';
	a = 'A';
	d = 'D';
	char temp;
	if(num_disks % 2 == 0) {
		temp = a;
		a = d;
		d = temp;
	}
	
	total = pow(2,num_disks) -1;
	
	for(i = num_disks; i >= 1; i--) {
		push(src, i);
		//printf("success 2\n");
	}
	
	for (i = 1; i <= total; i++) {
		if (i % 3 == 1)
			move_to_frm(src, des, s, d);
		else if (i % 3 ==2)
			move_to_frm(src, aux, s, a);
		else if (i % 3 == 0) 
			move_to_frm(aux, des, a, d);
	}
}


void move_to_frm(stack * src, stack * des , char s, char d)
{
	int top_s;
	int top_d;
		
	top_s = pop(src);
	top_d = pop(des);
	
	if(top_s == -1) {
		push(src, top_d);
		print(d, s, top_d);
	}
	else if(top_d == -1) {
		push(des, top_s);
		print(s, d, top_s);
	}
	 else if (top_s > top_d) {
		push(src, top_s);
		push(src, top_d);
		print(d, s, top_d);
	}
	else if (top_s < top_d) {
		push(des, top_d);
		push(des, top_s);
		print(s, d, top_s);
	}
}

void print(char s, char d, int disk)
{
	printf("Disk-%d   %c------>%c\n",disk,s,d);
}

int main(void)
{
	stack * src;
	stack * des;	
	stack * aux;
	int num;
	
	scanf("%d", &num);
	
	src = create(num);
	aux = create(num);
	des = create(num);
	
	
	t_o_h(num, src, aux, des);
return 0;
}
