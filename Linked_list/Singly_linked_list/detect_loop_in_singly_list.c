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

void create_loop(node * head, int k)
{
	if (head == NULL) {
		return;
	}
	
	int i;
	node * temp;
	temp = head;
	for (i = 1; i < k && head != NULL; i++) {
		head = head -> next;
	}
	
	while(temp -> next != NULL) {
		temp  = temp -> next;
	}
	
	temp -> next = head;
}
	
int check_loop (node * head)
{
	if (head == NULL || head -> next == NULL) {
		return 0;
	}
	if (head -> next == head) {
		return 1;
	}
	node * ptr1;
	node * ptr2;
	
	ptr1 = head;
	ptr2 = head -> next -> next;
	
	while (ptr2 != NULL && ptr1 -> next != NULL) {
		if (ptr1 == ptr2) {
			return 1;
		}
		
		ptr1 = ptr1 -> next;
		ptr2 = ptr2 -> next -> next;
		
	}
	return 0;
}

int main(void)
{
	node * head;
	head = NULL;
		
	printf("1.insert_beg\n2.print\n3.create_loop_k\n4.check_loop\n5.end\n");
	int num;
	int k;
	int test;
	int end;
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
				scanf("%d", &k);
				create_loop(head, k);
				break;
			case 4:
				num = check_loop(head);
				if (num == 1) {
					printf("LOOP FOUND\n");
				} else {
					printf("LOOP NOT FOUND\n");
				}
			case 5:
				end = 0;
		}
	}
	
	return 0;
}
