#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} node;

node * insert_beg (node * head, int x)
{
	node * temp;
	temp = (node*)malloc(sizeof(node));
	temp -> next = head;
	temp -> data = x;
	return temp;
}

node * insert_end (node * head, int x)
{
	node * temp;
	node * fix;
	fix = head;
	temp = (node*)malloc(sizeof(node));
	temp -> next = NULL;
	temp -> data = x;
	if (head == NULL) {
		return temp;
	}
	while(head -> next != NULL) {
		head = head -> next;
	}
	
	head -> next = temp;
	return fix;
}
		
node * print (node * head)
{
	if(head == NULL) {
		return ;
	}
	printf("%d ", head -> data);
	print (head -> next);
}

node * merge (node * head, int a, int mid, int b)
{
	node * head1 = NULL;
	node * head2 = NULL;
	node * fix = head;
	int i;
	int j;
	node * temp;
	for (i = 0; i < a-1; i++) {	
		head = head -> next;
	}
	temp = head;
	for (i = a; i <= mid; i++) {
		head1 = insert_end (head1, head -> data);
		head = head -> next;
	}
	for (i = mid + 1; i <= b; i++) {
		head2 = insert_end (head2, head -> data);
		head = head -> next;
	}
	//print(head1);
	//printf("\n");
	//print(head2);
	//printf("\n");
	while(head1 != NULL && head2 != NULL) {		
		if (head1 -> data <= head2 -> data) {
			temp -> data = head1 -> data;
			head1 = head1 -> next;
		} else {
			temp -> data = head2 -> data;
			head2 = head2 -> next;
		}
		temp = temp -> next;
	}
	
	while ( head1 != NULL) {
		temp -> data = head1 -> data;
		temp = temp -> next;
		head1 = head1 -> next;
	}
		
	while (head2 != NULL ) {
		temp -> data = head2 -> data;
		temp = temp -> next;
		head2 = head2 -> next;
	}
	return 	fix;
}
		 
		
node * merge_sort (node * head, int a, int b)
{
	if (a >= b || head == NULL || head -> next == NULL) {
		return head;
	}
	
	int mid;
	mid = a + (b - a) / 2;
	merge_sort (head, a, mid);
	merge_sort (head, mid + 1, b);
	
	merge(head, a, mid, b);
	return head;
	
}
	
int main(void)
{
	node * head;
	head = NULL;
	int n;
	scanf("%d", &n);
	
	int i;
	int x;
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		head = insert_beg(head, x);
	}
	
	head = merge_sort (head, 1, n);
	print(head);
	printf("\n");
	return 0;
}
	
	
