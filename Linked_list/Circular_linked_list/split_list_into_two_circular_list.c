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

node * insert_aft (node * tail, int k, int data)
{
	if (tail == NULL) {
		printf("Invalid Request\n");
		return tail;
	}
	
	node * temp;
	temp = tail;
	
	while (k && temp -> next != tail) {
		temp = temp -> next;
		k--;
	}
	
	node * new;
	node * temp1;
	temp1 = NULL;
	new = (node*)malloc(sizeof(node));
	
	new -> data = data;
	new -> next = NULL;
	
	if (temp -> next == tail && k == 1) {
		temp1 = tail -> next;
		tail -> next = new;
		new -> next = temp1;
		return new;
	}
	
	if ( k == 0 ) {
		temp1 = temp -> next;
		temp -> next = new;
		new -> next = temp1;
		return tail;
	}
	
	printf("Invalid Request\n");
	return tail;
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
	while(temp != tail -> next) {
		printf("%d ", temp -> data);
		temp = temp -> next;
		
	}
	printf("\n");
	return ;
}	

node * split (node ** tail)
{
	if (*tail == NULL) {
		printf("List is empty\n");
	}
	
	if ((*tail) -> next == *tail) {
		printf("NOT POSSIBLE\n");
		return *tail;
	}
	
	node * temp = NULL;
	node * temp1 = NULL;
	
	int ctr = 1;
		
	temp = *tail;	
	
	while((temp) -> next != *tail) {
		ctr ++;
		temp = temp -> next;
	}
	temp  = *tail;	
	//printf("%d---->\n",ctr);
	
	temp1 = (*tail) -> next;
	
	ctr = ctr / 2;
	while (ctr) {
		temp = temp -> next;
		ctr --;
	}
	
	(*tail) -> next = temp -> next;
	temp -> next = temp1;
	
	return temp;
} 
int main(void)
{
	node * tail;
	node * tail1;
	tail = NULL;
	tail1 = NULL;
		
	printf("1.insert_beg\n2.insert_end\n3.print_all\n4.split\n5.print_part1\n6.print_part2\n7.end\n");
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
				tail1 = split(&tail);
				break;
			case 5:
				print(tail1);
				break;
			case 6:
				print(tail);
				break;
			case 7:
				end = 0;
		
		}
	}
	return 0;
}
