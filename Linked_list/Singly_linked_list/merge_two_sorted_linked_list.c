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

void print(node * head)
{
	while(head != NULL) {
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
	return ;
}

node * merge_link(node * head1, node * head2)
{
	if( head1 == NULL && head2 == NULL) {
		return head1;
	}
	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}
	
	node * crnt1;
	node * crnt2;
	
	crnt1 = NULL;
	if(head1 -> data <= head2 -> data) {
		crnt1 = head1;
		crnt2 = crnt1;
		head1 = head1 ->  next;
	} else {
		crnt1 = head2;
		crnt2 = crnt1;
		head2 = head2 -> next;
	}
	
	while (head1 != NULL && head2 != NULL) {
		if (head1 -> data <= head2 -> data) {
			crnt1 -> next = head1;
			crnt1 = head1;
			head1 = head1 -> next;
		} else {
			crnt1 -> next = head2;
			crnt1 = head2;
			head2 = head2 -> next;
		}
	}
	
	if(head1 != NULL) {
		crnt1 -> next = head1;
	} else {
		crnt1 -> next = head2;
	}
	return crnt2;
}			
	
int main(void)
{
	node * head1;
	node * head2;
	head1 = NULL;
	head2 = NULL;
	printf("1.insert_beg_1\n2.insert_beg_2\n3.print_1\n4.print_2\n5.merge_links_linked_list_1\n6.end\n");
	
	int end;
	int test;
	int num;
	end = 1;
	test = 0;
	
	while(end) {	
		scanf("%d", &test);
		switch(test) {
			case 1:
				scanf("%d", &num);
				head1 = insert_beg(head1, num);
				break;
			case 2:
				scanf("%d",  &num);
				head2 = insert_beg(head2, num);
				break;
			case 3:
				print(head1);
				break;
			case 4:
				print(head2);
				break;
			case 5:
				head1 = merge_link(head1, head2);
				break;
			case 6:
				end = 0;
				break;	
		}
	}
	return 0;
}
