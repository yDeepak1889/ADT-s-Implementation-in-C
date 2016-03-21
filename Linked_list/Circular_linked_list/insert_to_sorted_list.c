#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;

} node;

node * insert_beg (node * tail, int data)
{
	node * new;
	new = (node*)malloc(sizeof(node));
	new -> data = data;
	new -> next = NULL;
	if (tail == NULL) {
		new -> next = new;
		return new;
	}
	
	node * temp;
	temp = tail->next;
	tail -> next = new;
	new -> next = temp;
	return tail;
}

node * insert_end (node * tail, int data)
{
	node * new;
	new = (node*)malloc(sizeof(node));
	new -> next = NULL;
	new -> data = data;
	
	if(tail == NULL) {
		new -> next = new;
		return new;
	}
	
	node * temp;
	temp = tail -> next;
	new -> next = temp;
	tail -> next = new;	
	return new;
}

void print(node * tail)
{
	if (tail == NULL) {		
		printf("List is empty\n");
		return ;
	}
	
	node * temp;
	temp = tail -> next;
	printf("%d ", temp -> data);
	temp = temp -> next;
	while(temp != tail->next) {
		printf("%d ", temp -> data);
		temp = temp -> next;
		
	}
	printf("\n");
	return ;
}

node * insert_num (node * tail, int num)
{
	node * new;
	new = (node*)malloc(sizeof(node));
	new -> next = NULL;
	new -> data = num;
	if (tail == NULL) {
		new -> next = new;
		new -> data = num;
		return new;
	}
	
	node * temp;	
	node * temp1;
	temp1 = NULL;
	temp = tail;
	
	if(num > tail -> data) {
		temp1 = tail -> next;
		tail -> next = new;
		new -> next = temp1;
		return new;
	}
	
	temp1 = NULL;
	temp = tail;
	
	while(temp -> next -> data < num) {
		temp =temp -> next;
	}
	
	temp1 = temp -> next;
	temp -> next = new;
	new -> next = temp1;
	return tail;
}

int main(void)
{
	node * tail;
	tail = NULL;
	
	printf("1.insert_beg\n2.insert_end\n3.print\n4.insert_num\n5.end\n");
	
	int test;
	int end;
	int num;
	end = 1;
	while(end) {
		scanf("%d", &test);
		switch(test) {
			case 1:
				scanf("%d", &num);
				tail = insert_beg(tail, num);
				break;
			case 2:
				scanf("%d", &num);
				tail = insert_end (tail, num);
				break;
			case 3:
				print(tail);
				break;
			case 4:
				scanf("%d", &num);	
				tail = insert_num (tail, num);
				break;
			case 5:
				end = 0;
		}
	}
	return 0;
}
