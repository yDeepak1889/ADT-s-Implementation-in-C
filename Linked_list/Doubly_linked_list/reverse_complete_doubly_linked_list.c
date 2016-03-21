#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node * next;
	struct node * prev;
}node;

node * insert_beg (node * head, int num)
{
	node * new;
	new = (node*)malloc(sizeof(node));
		
	new -> next = head;
	new -> prev = NULL;
	
	new -> data = num;
	if(head != NULL) {
		head -> prev = new;
	}
	return new;
}

node * insert_end (node * head, int  num)
{	node * new;
	new = (node*)malloc(sizeof(node));
	
	new -> data = num;
	new -> next = NULL;
	new -> prev = NULL;
	if (head == NULL) {
		return head;
	}
	node * temp;
	temp = head;
	
	while (head -> next != NULL) {
		head = head -> next;
	}
	
	head -> next = new;
	new -> prev = head;
	return temp;
}


void print_all (node * head)
{
	if(head == NULL) {
		printf("Empty List\n");
		return ;
	}
		
	while(head != NULL) {
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
	return ;
}

node * reverse (node * head)
{
	if (head == NULL) {
		return NULL;
	}
	
	node * prev;
	node * current;
	node * next;
	
	prev = NULL;
	current = head;
	next = NULL;
	
	while(current != NULL) {
		next = current -> next;
		current -> next = prev;
		current -> prev = next;
		prev = current;
		current = next;	
	}
	return prev;
}


int main (void)
{
	node * head;
	head = NULL;
	
	printf("1.insert_beg\n2.insert_end\n3.print_all\n4.reverse\n5.end\n");
	
	int end;
	int test;
	int num;
	
	end = 1;
	
	while (end) {
		scanf("%d", &test);
		switch (test){
			case 1:
				scanf("%d", &num);
				head = insert_beg (head, num);
				break;
			case 2:
				scanf("%d", &num);
				head = insert_end (head, num);
				break;
			case 3:
				print_all(head);
				break;
			case 4:
				head = reverse(head);
				break;
			case 5:
				end = 0;
				break;
		}
	}
	
	return ;
}
