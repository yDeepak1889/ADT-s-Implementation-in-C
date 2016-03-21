#include<stdio.h>
#include<stdlib.h>

struct queue {
	int capacity;
	int front;
	int rear;
	int * arr;
};

struct queue * create (int capacity) 
{
	struct queue * que = (struct queue *) malloc (sizeof (struct queue));
	que -> capacity = capacity;
	que -> front = 0;
	que -> rear = 0;
	que -> arr = (int*)malloc(sizeof (int) * capacity);
	return que;
}

void enqueue (struct queue * q, int num)
{
	if (q -> front == (q -> rear + 1) % q -> capacity) {
		printf("Overflow\n");
		return ;
	}
	
	q -> arr[q -> rear] = num;
	q -> rear = (q -> rear + 1) % q -> capacity;
}

int dequeue (struct queue * q)
{
	if (q -> rear  == q -> front) {
		return -1;
	}
	
	int temp;
	temp = q -> arr[q -> front];
	q -> front = (q -> front + 1) % q -> capacity;
	return temp;
}

int  rear (struct queue * q)
{
	if (q -> front == q -> rear) {
		printf("Empty queue\n");
		return -1;
	}
	
	if (q -> rear == 0) {
		return q -> arr[q -> capacity -1];
	} 
	return q -> arr[q -> rear - 1];
}
int isempty (struct queue * q)
{
	if ( q -> front == q -> rear) {
		return 1;
	} else {
		return 0;
	}
}

int isfull (struct queue * q)
{
	if ( (q -> rear + 1) % q -> capacity == q -> front) {
		return 1;
	} else {
		return 0;
	}
}
int front (struct queue * q)
{
	if (q -> front == q -> rear) {
		printf("Empty queue\n");
		return -1;
	} else {
		return q -> arr[q -> front];
	}
}

	
	
int main(void)
{
	int capacity;
	scanf("%d", &capacity);
	struct queue * q;
	q = create (capacity);
	
	printf("1.enqueue\n2.dequeue\n3.front\n4.rear\n5.isempty\n6.isfull\n7.end\n");
	int end;
	int test;
	int num;
	
	end = 1;
		
	while (end) {
		scanf("%d", &test);
		switch (test){
			case 1:
				scanf("%d", &num);
				enqueue(q, num);
				break;
			case 2:
				num = dequeue(q);
				if (num == -1) {
					printf("Underflow\n)");
				} else {
					printf("%d\n",num);
				}
				break;
			case 3:
				num = front(q);
				if (num != -1) {
					printf("%d\n", num);
				}
				break;
			case 4:
				num = rear(q);
				if (num != -1) {
					printf("%d\n", num);
				}
				break;
			case 5:
				num = isempty(q);
				if (num == 0) {
					printf("False\n");
				} else {
					printf("True\n");
				}
				break;
			case 6:
				num = isfull(q);
				if (num == 0) {			
					printf("False\n");
				} else {
					printf("True\n");
				}
				break;
			case 7:
				end = 0;
				break;
		}
	}
	return 0;
}
