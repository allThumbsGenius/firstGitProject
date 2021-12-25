#include<stdio.h>
#define QUEUESIZE 12
int fullQueue(int *head, int *tail) {
	return (*head == (*tail + 1)%QUEUESIZE);
}
int emptyQueue(int *head, int *tail) {
	return (*head == *tail);
}
void enQueue(int Q[], int x, int *head, int *tail) {
		Q[*tail] = x;
		*tail=*tail+1;
		*tail %= QUEUESIZE;
}
int deQueue(int Q[], int *head, int *tail) {
	int x;
	if (emptyQueue(head, tail)) {
		return -1;
	}
	else {
		x = Q[*head];
		*head=*head+1;
		*head %= QUEUESIZE;
		return x;
	}
}
int main() {
	int head = 0, tail = 0;
	int queue[QUEUESIZE];
	int select, x, i, deQueueNum, count=0;

	while (1) {
		printf("1. enQueue\n2. deQueue\n\n");
		printf("할 동작: ");
		scanf("%d", &select);
		if (fullQueue(&head, &tail) && select==1) {
			printf("*****full queue*****\n");
			continue;
		}
		if(select!=1 && select !=2){
			break;
		}
		switch (select) {
		case 1: printf("넣을 값: "); scanf("%d", &x); enQueue(queue, x, &head, &tail); break;
		case 2: deQueueNum = deQueue(queue, &head, &tail); if (deQueueNum == -1) { printf("queue 부족\n"); }
				else { printf("deQueueNum: %d\n", deQueueNum);} break;
		}
		printf("tail: %d\nhead: %d\n", tail, head);
		printf("\nqueue: ");
		for (i = head, count = 0;; i++, count++) {
			i %= QUEUESIZE;
			if (head>tail && count == 12-(head-tail)) {
				break;
			}
			else if (tail>head && count == tail - head) {
				break;
			}
			else if (tail == head) {
				break;
			}
			printf("%d ", queue[i]);
		}
		printf("\n-----------------------\n");
	}


}
