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

node * insert_aft (node *  head, int k , int num)
{
	if (head == NULL) {
		printf ("Invalid Request\n");
		return head;
	}	
	
	node * new;
	new = (node*) malloc (sizeof(node));
	new -> data = num;
	new -> next = NULL;
	new -> prev = NULL;
	node * temp;
	temp = head;
	
	while(k-1 && head -> next != NULL) {
		head = head -> next;
		k--;
	}
	if(k - 1 != 0 && head ->next == NULL) {
		printf("Invalid Request\n");
		return temp;
	}
	new -> next = head -> next;	
	new -> prev = head;
	head -> next = new;
	
	return temp;
}

node * insert_bef (node * head, int k, int num)
{
	if (head == NULL) {
		printf("Invalid Request\n");
		return head;
	}	

	node * new;
	node * temp;
	temp = head;
	
	new = (node*)malloc(sizeof(node));
	
	new -> next = NULL;
	new -> prev = NULL;
	
	new -> data = num;
	
	if (k == 1) {
		new -> next = head;
		head -> prev = new;
		return new;
	}
	
	while(k-2 && head -> next != NULL) {
		head = head -> next;
		k--;
	}
	
	if (head -> next == NULL) {
		printf("Invalid Request\n");
		return temp;
	}
	
	new -> next = head -> next;
	
	new -> prev = head;
	
	head -> next = new;
		
	return temp;
}


node * delete_beg (node * head)
{
	if(head == NULL) {
		printf("Invalid Request\n");
		return head;
	}
	
	if (head -> next == NULL) {	
		free(head);
		return NULL;
	}
	
	node * temp;
	temp = head -> next;
	temp -> prev = NULL;
	
	free(head);
	return temp;
}

node * delete_end (node * head)
{
	if (head == NULL) {
		printf("Invalid Request\n");
		return head;
	}
	
	node * temp;
	node * temp1;
	temp1 = head;
	temp = NULL;
	
	if (head -> next == NULL) {
		free(head);
		return NULL;
	}
	
	while(head -> next != NULL) {
		head = head -> next;
	}
	
	temp = head -> prev;
	
	free(head);
	
	temp -> next = NULL;
	
	return temp1;
}
	

node * delete_aft (node * head, int k) 
{
	if (head == NULL  || head -> next == NULL) {
		printf("Invalid Request\n");
		return head;
	}	
	node * temp;
	temp = head;
	while(k && head -> next != NULL) {
		head = head -> next;
		k--;
	}
	
	if(head -> next == NULL && k != 0 ) {
		printf("Invalid Request\n");
		return temp;
	}
	
	node * temp1;
	temp1 = head -> prev;
	temp1 -> next = head -> next;
	
	free(head);
	return temp1;
}

node * delete_bef (node * head, int k)
{
	if (k == 1 || head == NULL || head -> next == NULL) {
		printf("Invalid Request\n");
		return head;
	}
	
	node * temp;
	node * temp1;
	temp = head;
	temp1 = head;
	if (k == 2) {
		temp = head -> next;
		temp -> prev = NULL;
		free(head);
		return temp;
	}
		
	while(k-2 && head -> next != NULL) {
		head = head -> next;
		k--;
	}	
	
	if (k-1 != 0 && head -> next == NULL) {
		printf("Inalid Request\n");
		return temp1;
	}
	
	temp = head -> prev;
	temp -> next = head -> next;
	free(head);
	return temp1;
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
		

int main(void)
{
	node * head;
	head = NULL;
	
	printf ("1.insert_beg\n2.insert_end\n3.insert_aft\n4.insert_bef\n5.delete_beg\n6.delete_end\n7.delete_aft\n8.delete_bef\n9.print_all\n10.end\n");
	int end;
	int test;
	int num;
	int k;
	
	while(end) {
		scanf("%d", &test);
		switch(test) {
			case 1:
				scanf("%d", &num);
				head = insert_beg (head, num);
				break;
			case 2:
				scanf("%d", &num);
				head = insert_end (head, num);
				break;
			case 3:
				scanf("%d %d", &k, &num);
				head = insert_aft (head, k, num);
				break;
			case 4:
				scanf("%d %d", &k, &num);
				head = insert_bef(head, k, num);
				break;
			case 5:
				head = delete_beg(head);
				break;
			case 6:
				head = delete_end (head);
				break;
			case 7:
				scanf("%d", &k);
				head = delete_aft(head, k);
				break;
			case 8:
				scanf("%d", &k);
				head = delete_bef(head, k);
				break;
			case 9:
				print_all(head);
				break;
			case 10:
				end  = 0;
		}
	}
	return 0;
}
