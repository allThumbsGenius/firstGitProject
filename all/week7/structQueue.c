#include<stdio.h>
typedef int element;//데이터형을 편하게 바꾸어 줄 수 있다.
typedef struct {
	element *data;
	int tail;
	int head;
	int size;
}QUEUE;
//(*q).tail == q->tail

void initQueue(QUEUE *q) {
	int sizeQueue;
	printf("원하는 큐의 크기: ");
	scanf("%d", &sizeQueue);
	q->size = sizeQueue;
	q->head = 0;
	q->tail = 0;
	q->data = (element *)malloc(sizeQueue * 4);
}
int fullQueue(QUEUE *q) {
	return (q->head == (q->tail + 1)%(q->size));
}
int emptyQueue(QUEUE *q) {
	return (q->head == q->tail);
}
void enQueue(QUEUE *q, int x) {
	if (fullQueue(q)) {
		printf("****queue is full****\n");
		return NULL;
	}
	q->data[q->tail] = x;
	q->tail = q->tail + 1;
	q->tail = q->tail % q->size;
}
int deQueue(QUEUE *q) {
	int x;
	if (emptyQueue(q)) {
		printf("****queue is empty****\n");
		return -1;
	}
	x = q->data[q->head];
	q->head = q->head + 1;
	q->head = q->head % q->size;
	return x;
}
int main() {
	QUEUE queue1;
	int select, x,i,count, queueNum;

	initQueue(&queue1);
	while (1) {
		printf("1. enQueue\n2. deQueue\n\n");
		printf("할 동작: ");
		scanf("%d", &select);
		if(select!=1 && select!=2){
			break;
		}
		switch (select) {
		case 1: printf("넣을 값: "); scanf("%d", &x); enQueue(&queue1, x); break;
		case 2: queueNum = deQueue(&queue1); if (queueNum != -1) { printf("\ndeQueue: %d\n", queueNum); } break;
		}

		printf("\nqueue: ");
		for (i = queue1.head, count = 0;; i++, count++) {
			if (queue1.head > queue1.tail && count == 12 - (queue1.head - queue1.tail)) {
				break;
			}
			else if (queue1.head == queue1.tail) {
				break;
			}
			else if (queue1.tail - queue1.head == count) {
				break;
			}
			printf("%d ",queue1.data[i]);
		}
		printf("\n\n");
	}
}
