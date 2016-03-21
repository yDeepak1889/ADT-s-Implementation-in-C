#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct
{
	int item;
	int pri;
}element;

typedef struct 
{
	int front, rear,size;
	int capacity;
	element * arr;
}queue;

queue * create(int capacity)
{
	queue * q;
	q = (queue*)malloc(sizeof(queue));
	q->front  = 0;
	q->rear = -1;
	q->size = 0;
	q->arr = (element*)malloc(sizeof(element) * capacity);
	q->capacity = capacity;
	return q;
}

void enque(queue * q, int num, int pri)
{
	if(q->size == q->capacity) {
		printf("Oveflow\n");
		return ;
	}
	q->size ++;
	
	q->arr[(q->rear + 1) % q->capacity].item = num;
	q->arr[(q->rear + 1) % q-> capacity].pri = pri;
	q->rear = (q->rear + 1) % q -> capacity;
	return ;
}
	
int deque(queue * q)
{
	if(q -> size == 0) {
		return INT_MAX;
	}
	
	int max = INT_MIN;
	int i;
	for(i = q -> front; i <= q -> front + q->size; i++) {
		if(max < q -> arr[(i) % q -> capacity].pri) {
			max = q -> arr[(i) % q -> capacity].pri;
		}
	}
	
	i = q -> front;
	int num;
	while(q->arr[(i) % q->capacity].pri != max) {
		i++;
	}
	num = q -> arr[i % q-> capacity].item;
	while ( i % q->capacity != q->front) {
		q->arr[((i) % q -> capacity)].item = q->arr[(i % q -> capacity)-1].item;
		q->arr[((i) % q -> capacity)].pri = q->arr[(i % q -> capacity)-1].pri;
		i --;
	}
	q->front = (q->front + 1 ) % q -> capacity;
	q -> size --;

	return num;
}
	
int front(queue * q)
{
	if(q->size == 0) {
		return INT_MIN;
	}
	return q->arr[q->front].item;
}

int rear(queue * q) 
{
	if(q->size == 0) {
		return INT_MIN;
	}
	return q->arr[q->rear].item;
}
	
int main(void)
{	
	int capacity;

	scanf("%d", &capacity);
		
	queue * q;

	q = create(capacity);
	
	printf("1.enqueue\n2.dequeue\n3.front\n4.rear\n5.end\n");
	
	int pri;
	int num;
	int test;
	int end;

	end = 1;	
	
	while(end) {

		scanf("%d", &test);

		switch(test) {
			case 1:
				scanf("%d %d", &num, &pri);
				enque(q, num, pri);
				break;
			case 2:
				num = deque(q);
				if(num == INT_MAX) {
					printf("Underflow\n");
				}else {
					printf("%d\n", num);
				} 		
				break;
			case 3:
				num = front(q);
				if(num == INT_MAX) {
					printf("Queue is empty\n");
				} else {
					printf("%d\n",num);
				}
				break;
			case 4:
				num = rear(q);
				if (num == INT_MAX) {
					printf("Queue is empty\n");
				} else {
					printf("%d\n", num);
				}
				break;
			case 5:
				end = 0;
				break;
		}
	}
	
	return 0;
}
	
	
