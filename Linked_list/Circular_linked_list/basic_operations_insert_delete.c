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

node * insert_bef (node * tail, int k, int data)
{
	if (tail == NULL) {
		printf("Invalid Request\n");
		return tail;
	}
	
	node * temp;
	node * new;
	
	new = (node*)malloc(sizeof(node));
	new -> data = data;
	new -> next = NULL;
	
	if (k == 1) {
		temp = tail -> next;
		tail -> next = new;
		new -> next = temp;
		return tail;
	}
	temp = tail;
	while(k-1 && temp -> next != tail) {
		temp = temp -> next;
		k--;
	}
	node * temp1;
	if (k-1 == 0) {
		temp1 = temp -> next;
		temp -> next = new;
		new -> next = temp1;
		return tail;
	}
	printf("Invalid Request\n");
	return tail;
}


node * delete_beg (node * tail)
{
	if (tail == NULL) {
		printf("Invalid Request\n");
		return tail;
	}
	if (tail -> next == tail) {
		free(tail);
		return NULL;
	}
	node * temp;
	node * temp1;
	
	temp = tail -> next;
	temp1 = temp -> next;
	
	tail -> next = temp1;
	free(temp);
	return tail;
}
	
node * delete_end (node * tail)
{
	if (tail == NULL) {
		printf("Invalid Request\n");
		return tail;
	}
	
	if (tail -> next == tail) {
		free(tail);
		return NULL;
	}
	
	node * temp;
	temp = tail;
	while(temp -> next != tail) {
		temp = temp -> next;
	}	
	
	node * temp1;
	temp1 = tail -> next;
	temp -> next = temp1;
	free(tail);
	return temp;
}

node * delete_aft (node * tail, int k)
{
	if (tail == NULL) {
		printf("Invalid Request\n");
		return tail;
	}
	if(tail -> next == tail && k==1) {
		free(tail);
		return NULL;
	}
	
	node * temp;
	node * temp1;
	temp = NULL;
	temp1 = NULL;
	
	temp = tail;
	while(k && temp -> next != tail) {
		k--;
		temp = temp -> next;
	}
	if (k == 1 && temp -> next == tail) {
		temp1 = tail -> next;
		tail -> next = temp1 -> next;
		free(temp1);
		return tail;
	}
	
	if (k == 0 && temp -> next == tail) {
		temp1 = tail -> next;
		temp -> next = temp1;
		free(tail);
		return temp;
	}
	
	temp1 = temp -> next;
	temp -> next = temp -> next -> next;
	free(temp1);
	return tail;
}

node * delete_bef (node * tail, int k)
{	
	if (tail == NULL) {
		printf("Invalid Request\n");
		return tail;
	}
	
	if(tail -> next == tail && k == 1) {
		free(tail);
		return NULL;
	}
	node * temp1;
	temp1 = tail;
	node * temp2 = NULL;
	if (k == 1) {
		while (temp1 -> next != tail) {
			temp1 = temp1 -> next;		
		}
		temp2 =	tail -> next;
		temp1 -> next = temp2;
		free(tail);
		return temp1;
	}	
	while(k-2 && temp1 -> next != tail) {
		temp1 = temp1 -> next;
		k--;
	}
	
	temp2 = temp1 -> next;
	temp1 -> next = temp2 -> next;
	free(temp2);
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
	while(temp != tail->next) {
		printf("%d ", temp -> data);
		temp = temp -> next;
		
	}
	printf("\n");
	return ;
}	
	
int main(void)
{
	node * tail;
	tail = NULL;	
	printf("1.insert_beg\n2.insert_end\n3.insert_after_k\n4.insert_before_k\n5.deletion_after_k\n6.deletion_before_k\n7.deletion_beg\n8.deletion_end\n9.print_all\n10.end\n");
	int test;
	int end;
	int num;	
	int k;
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
				scanf("%d", &k);
				scanf("%d", &num);
				tail = insert_aft(tail, k , num);
				break;
			case 4:
				scanf("%d", &k);
				scanf("%d", &num);
				tail = insert_bef(tail, k, num);
				break;
			case 5:
				scanf("%d", &k);
				tail = delete_aft(tail, k);
				break;
			case 6:
				scanf("%d", &k);
				tail = delete_bef(tail, k);
				break;
			case 7:
				tail = delete_beg(tail);
				break;
			case 8:
				tail = delete_end(tail);
				break;
			case 9:
				print(tail);
				break;
			case 10:
				end = 0;
		}
	}
	return 0;
}
				
