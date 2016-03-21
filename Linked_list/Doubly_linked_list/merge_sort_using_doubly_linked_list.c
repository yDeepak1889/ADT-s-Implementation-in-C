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

node * split (node * head)
{
	node * fast;
	node * slow;
	
	fast = head;
	slow = head;
	
	while(fast -> next && fast -> next -> next) {
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	
	node * temp;
	temp = slow -> next;
	slow -> next = NULL;
	
	return temp;
}

node * merge (node * head, node * second)
{
	int num;
	node * temp;
	node * temp1;
	if (head -> data <= second -> data) {
		temp = head;
		head = head -> next;
	} else {
		num = second -> data;
		second -> data = head -> data;
		head -> data = num;
		temp = head;
		head = head -> next;
	}
	temp1 = temp;
	while (head != NULL && second != NULL) {
		if (head -> data <= second -> data) {
			temp -> next = head;
			temp = temp -> next;
			head -> prev = temp;
			head = head -> next;
		} else {
			temp -> next = second;
			temp = temp -> next;
			second -> prev = temp;
			second = second -> next;
		}
	}
			
	if (head != NULL) {
		temp -> next = head;
		temp = temp -> next;
		head -> prev = temp;
	} else if (second != NULL) {
		temp -> next = second;
		temp = temp -> next;
		second -> prev = temp;
	}
	//print_all (temp);
	return temp1;
}
		
		
node * mergeSort(node * head)
{
	if (head == NULL || head -> next == NULL) {
		return head;
	}
	
	node * second;
	second = split (head);
	head = mergeSort (head);
	second = mergeSort (second);
	//print_all(head);
//	print_all(second);
	node * temp;
	temp = merge (head, second);
	//print_all(temp);
	return temp;
	
}

int main(void)
{
	node * head;
	head = NULL;
	
	printf ("1.insert_beg\n2.insert_end\n3.ptint_all\n4.merge_sort\n5.end\n");
	
	int test;
	int end;
	int num;
	
	end = 1;
	
	while (end) {
		scanf("%d", &test);
		switch (test) {
			case 1:
				scanf("%d", &num);
				head = insert_beg (head, num);
				break;
			case 2:
				scanf("%d", &num);
				head = insert_end (head, num);
				break;
			case 3:
				print_all (head);
				break;
			case 4:
				head = mergeSort(head);
				break;
			case 5:	
				end = 0;
				break;
		}
	}
	
	return 0;
}
