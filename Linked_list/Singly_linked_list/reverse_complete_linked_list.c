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

node * reverse_loop (node * head)
{
	if( head == NULL) {
		return head;
	}	
	
	node * prev;
	node * current;
	node * next;
	prev = NULL;
	current = NULL;
	
	while(head != NULL) {
		current = head;
		next = head -> next;
		head -> next = prev;
		prev = current;
		head = next;
	}
	return prev;
}

node * reverse_recur(node *head)
{
	if (head -> next == NULL) {
		return head;
	}
	node * temp;
	temp = reverse_recur (head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return temp;
}


int main(void)
{
	node * head;
	head = NULL;
	printf("1.insert_beg\n2.print\n3.reverse_loop\n4.reverse_recursion\n5.end\n");
	
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
				head = insert_beg(head, num);
				break;
			case 2:
				print(head);
				break;
			case 3:
				head = reverse_loop(head);
				break;
			case 4:
				head = reverse_recur(head);
				break;
			case 5:
				end = 0;
				break;
		}
	}
	return 0;
}
	
