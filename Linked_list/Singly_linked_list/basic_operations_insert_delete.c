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

node * insert_end(node * head, int num)
{
	node * temp;
	node * temp1;
	temp1 = head;
	temp = (node*)malloc(sizeof(node));
	temp -> next = NULL;
	temp -> data = num;
	if(head == NULL) {
		return temp;
	}
	
	while (head -> next != NULL) {
		head = head -> next;
	}
	head -> next = temp;
	return temp1;
}

node * insert_aft_k(node * head, int k, int num)
{
	if(head == NULL) {
		printf("Invalid request\n");
		return head;
	}
	node * temp;
	node * temp1;
	temp1 = head;
	
	while((k - 1) && head != NULL) {
			head = head -> next;
			k--;
	}
	
	if(head == NULL) {
		printf("Invalid Request\n");
		return temp1;
	}
	
	temp = (node*)malloc(sizeof(node));
	temp -> next = head -> next;
	head -> next= temp;
	temp -> data = num;
	return temp1;
}


node * insert_bef_k(node * head, int k, int num)
{
	node * temp;
	node * temp1;
	temp1 = head;
	
	if(k == 1) {
		temp = (node*)malloc(sizeof(node));
		temp -> next = head;
		temp -> data = num;
		return temp;
	}
	
	while((k - 2) && head -> next != NULL) {
		head = head -> next;
		k--;
	}
	if(head->next == NULL) {
		printf("Invalid Request\n");
		return temp1;
	}
	
	temp = (node*)malloc(sizeof(node));
	temp -> next = head ->next;
	head-> next = temp;
	temp -> data = num;
	return temp1;
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

node * delete_beg(node * head)
{
	if(head == NULL) {
		printf("Invalid Request\n");
		return head;
	}
	node * temp;
	temp = head -> next;
	free (head);
	return temp;
}

node * delete_end(node * head)
{
	if(head == NULL) {
		printf("Invalid Request\n");
		return head;
	}
	
	node * temp;
	node * temp1;
	temp1 = head;
	
	if(head -> next == NULL) {
		free(head);
		return NULL;
	}
	
	while(head -> next -> next != NULL) {
		head = head -> next;
	}
	
	temp = head -> next;
	head -> next = NULL;
	free(temp);
	return temp1;
}

node * delete_aft_k(node * head, int k)
{
	if(head == NULL || head -> next == NULL) {
		printf("Invalid Request\n");
		return head;
	}
	node * temp;
	node * temp1;
	temp = head;
	
	while(k - 1 && head != NULL) {
		head = head -> next;
		k--;
	}
	
	if(head -> next == NULL || head -> next == NULL) {
		printf("Invalid Request\n");
		return temp;
	}
	temp1 = head -> next;
	head -> next = head -> next -> next;
	free (temp1);
	return temp;
}

node * delete_bef_k (node * head, int k)
{
	if (head == NULL) {
		printf("Invalid Request\n");
		return head;
	}
	
	if(k == 1) {
		printf("Invalid Request\n");
		return head;
	}
	
	if(head -> next == NULL) {
		printf("Invalid Request\n");
		return head;
	}
	node * temp1;
	
	temp1 = head;
	
	if (k == 2) {
		temp1 = head -> next;
		free (head);
		return temp1;
	}
	
	while(k - 3 && k >0 && head != NULL) {
		head = head -> next;
		k--;
	}
	
	if (head == NULL) {
		printf("Invalid Request\n");
		return temp1;
	}
	
	node * temp;
	temp = head -> next;
	head -> next = head -> next -> next;
	free (temp);
	return temp1;
}
		
int count_loop(node * head)
{
	int count =0 ;
	while (head != NULL) {
		count++;
		head = head -> next;
	}
	return count;
}

int count_recur(node * head)
{
	if(head == NULL) {
		return 0;
	}
	return count_recur(head->next) + 1;
}

int main(void)
{
	node * head;
	head = NULL;
	printf("1.insert at begginng\n2.insert at end\n3.insert after kth node\n4.insert before kth node\n5.print\n6.delete_beg\n7.delete_end\n8.delete after kth\n9.delete before kth \n10.count_using_loop\n11.count_using_recusion\n12.end\n");
	int test;
	int end = 1;
	int num;
	int k;
	while(end) {
		scanf("%d", &test);
		switch(test) {
			case 1:
				scanf("%d", &num);
				head = insert_beg(head, num);
				break;
			case 2:
				scanf("%d", &num);
				head = insert_end(head, num);
				break;
			case 3:
				scanf("%d", &k);
				scanf("%d", &num);
				head = insert_aft_k(head, k, num);
				break;
			case 4:
				scanf("%d", &k);
				scanf("%d", &num);
				head = insert_bef_k(head, k, num);
				break;
			case 5:
				print(head);
				break;
			case 6:
				head = delete_beg(head);
				break;
			case 7:
				head = delete_end(head);
				break;
			case 8:
				scanf("%d", &k);
				head = delete_aft_k(head, k);
				break;
			case 9:
				scanf("%d", &k);
				head = delete_bef_k(head, k);
				break;
			case 10:
				num = count_loop(head);
				printf("%d\n", num);
				break;
			case 11:
				num = count_recur(head);
				printf("%d\n", num);
				break;
			case 12:
				end = 0;
				break;
		
		}
	}
	return 0;
}
