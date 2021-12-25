#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 100

typedef struct _Queue{
	int queue[QUEUE_SIZE];
	int head;
	int tail;
}Queue;

void relocate(Queue *Q, int which, int base){
	int size;
	int i,j;
	int *temp;
	if(Q->head>Q->tail){
		size=QUEUE_SIZE-(Q->head-Q->tail);
	}
	else{
		size=Q->tail-Q->head;
	}
	temp=(int *)malloc(size*4);
	if(which=='H'){
		for(i=Q->head,j=0;j<size;i++,j++){
			i%=QUEUE_SIZE;
			temp[j]=Q->queue[i];
		}
		for(i=base,j=0;j<size;i++,j++){
			i%=QUEUE_SIZE;
			Q->queue[i]=temp[j];
		}
		Q->head=base%QUEUE_SIZE;
		Q->tail=(base+size)%QUEUE_SIZE;
	}
	else if(which=='T'){
		for(i=Q->head,j=0;j<size;i++,j++){
			i%=QUEUE_SIZE;
			temp[j]=Q->queue[i];
		}
		for(i=(QUEUE_SIZE+(base-size))%QUEUE_SIZE,j=0;j<size;i++,j++){
			i%=QUEUE_SIZE;
			Q->queue[i]=temp[j];
		}
		Q->head=(QUEUE_SIZE+(base-size))%QUEUE_SIZE;
		Q->tail=base%QUEUE_SIZE;
	}
}
	
