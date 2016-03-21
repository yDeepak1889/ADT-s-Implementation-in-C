#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} node;

node * insert_beg (node * head, int data)
{	node * temp;
	temp = (node*)malloc(sizeof(node));
	temp -> next = head;
	temp -> data = data;
	
	return temp;
}

void print (node * head)
{
	if (head == NULL) {
		return;
	}
		
	printf("%d ", head -> data);
	print(head -> next);
	return;
}

node * revr_k (node * head, int k)
{
	if (head == NULL) {
		return head;
	}
	node * temp1;
	node * temp;
	node * current;
	node * next = head;
	node * prev;
	node * fix;
	node * fix_temp;
	temp = head;
	prev = NULL;
	fix_temp = head;
	
	int i;
	
	for (i = 0; i < k && next != NULL; i++) {
		current = next;
		next = current -> next;
		current -> next = prev;
		prev = current;
		temp1 = next;
		//printf("success %d\n", fix -> data);
		//head = head -> next;
	}
	fix = prev;
//	print(fix);
//	printf("%d\n", temp1 -> data);
	while(next != NULL) {
		prev = NULL;
		temp = next;
		for(i = 0; i < k && next != NULL; i++) {
			current = next;
			next = current -> next;
			current -> next = prev;
			prev = current;
			//printf("%d\n", next -> data);
		}
		//print(prev);
		fix_temp -> next = prev;
		//print(fix);
		fix_temp = temp;
	}
	return fix;
}
		
int main(void)
{
	node * head;
	head = NULL;
	
	printf("1.insert_beg\n2.print\n3.revr_k\n4.end\n");
	
	int test;
	int end;
	int num;
	
	end = 1;
	
	while (end) {
		scanf ("%d", &test);
		switch (test) {
			case 1:
				scanf("%d", &num);
				head = insert_beg(head, num);
				break;
			case 2:
				print(head);
				printf("\n");
				break;
			case 3:
				scanf("%d", &num);
				head = revr_k (head, num);
				break;
			case 4:
				end = 0;
		}
	}
	
	return 0;
}
