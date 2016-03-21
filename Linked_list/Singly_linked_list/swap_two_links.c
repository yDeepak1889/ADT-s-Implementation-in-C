#include<stdio.h>
#include<stdlib.h>

typedef struct linked
{
	int data;
	struct linked * next;
}node;

node * insert_beg(node * head, int num)
{
	node * temp;
	temp = (node*)malloc(sizeof(node));
	temp -> next = head;
	temp -> data = num;
	return temp;
}

void print (node * head)
{
	if (head == NULL) {
		printf("list is empty\n");
		return ;
	}
	
	while(head != NULL) {
		printf("%d ", head -> data);
		head = head -> next;
	}	
	printf("\n");

	return;
}

node * swap(node * head, int a, int b)
{
	if (head == NULL || head -> next == NULL) {
		printf("Invalid request\n");
		return head;
	}

	node * ptr_a;
	node * ptr_b;
	node * temp;
	temp = head;
	ptr_a = head;
	ptr_b = NULL;
	
	while(head -> next != NULL) {
		if (head -> next -> data == a) {
			ptr_a = head;
			//printf("%p\n", ptr_a);
		}if (head -> next -> data == b) {
			ptr_b == head;
			//printf("%d\n", ptr_b -> next -> data);
		}
		
		if (ptr_a != NULL && ptr_b != NULL) {
			printf("success0\n");
			break;
		}
		
		head = head -> next;
	}
	/*if (ptr_a == NULL || ptr_b  == NULL) {
		printf("Invalid request\n");
		printf("success1\n");
		return temp;
	}*/
	
	node * temp1;
	node * temp2;
	if (ptr_a -> data == a) {
		if (ptr_b == ptr_a) {
			temp = ptr_b -> next;
			ptr_a -> next = temp -> next;
			temp -> next = ptr_a;
			printf("success2\n");
			return temp;
		}else {
			temp1 = ptr_b -> next -> next;
			temp = ptr_b -> next;
			temp -> next = ptr_a -> next;	
			ptr_a -> next = temp1;
			
			ptr_b -> next = ptr_a;
			printf("success3\n");
			return temp;
		}
	}
	
	if (ptr_b == ptr_a -> next) {
		temp1 = ptr_b -> next -> next;
		temp2 = ptr_b;
		ptr_a -> next = ptr_b -> next;
		ptr_a -> next -> next = temp2;
		temp2 -> next = temp1;
		printf("success4\n");
		return temp;
	}
	
	temp1 = ptr_a -> next;
	temp2 = ptr_b -> next -> next;
	ptr_a -> next = ptr_b -> next;
	ptr_a -> next -> next = temp1 -> next;
	ptr_b -> next = temp1;
	ptr_b -> next -> next = temp2;
	printf("success5\n");
	return temp;
}				

int main (void)
{
	node * head;
	head = NULL;
	
	printf("1.insrt_beg\n2.print_all\n3.swap_a_b\n4.end\n");
	int test;
	int end;
	int num;
	int a;
	int b;
	end = 1;
	
	while(end) {
		scanf("%d", &test);
		switch(test) {
			case 1:
				scanf("%d", &num);
				head = insert_beg(head, num);
				break;
			case 2:
				print(head);
				break;
			case 3:
				scanf("%d %d", &a, &b);
				head = swap(head, a, b);
				break;
			case 4:
				end = 0;
		}
	}
	return 0;
}
				
				
