#include<stdio.h>
#include<stdlib.h>

#define N 0
#define NE 1
#define E 2
#define SE 3
#define S 4
#define SW 5
#define W 6
#define NW 7

typedef struct _Infor {
	int x;
	int y;
}Infor;

typedef struct _node {
	Infor data;
	int top;
	struct _node *next;
}node;

void push(node *s, int x, int y, int *top) {
	node *temp;
	temp = (node *)malloc(sizeof(node));
	while (s->next != NULL) {
		s = s->next;
	}
	temp->data.x = x;
	temp->data.y = y;
	temp->top = s->top + 1;
	temp->next = NULL;
	s->next = temp;
	*top = *top + 1;
}

void pop(node *s, int *top) {
	while (s->next->next!= NULL) {
		s = s->next;
	}
	s->next = NULL;
	*top = *top - 1;
}
void printStack(node *s) {
	while (s->next != NULL) {
		s = s->next;
		printf("(%d, %d)->", s->data.x, s->data.y);
	}
	printf("\n");
}
node head;
int start;
int move(int **maze, int **mark, int row, int col, Infor *stack, int *top) {
	node *temp;
	int i, a, b, failCount;
	int retN = 0, retNE = 0, retE = 0, retSE = 0, retS = 0, retSW = 0, retW = 0, retNW = 0;
	int retsum = 0;
	
	if (start==0) {
		head.data.x=NULL;
		head.data.y = NULL;
		head.top = -1;
		head.next = NULL;
		push(&head, stack->x, stack->y, top);
		start++;
	}
	
	temp = &head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	a = temp->data.x;
	b = temp->data.y;
	
	if (a == col-2 && b == row-2) {
		retsum = 1;
		
	}
	else {
		for (i = N; i <= NW; i++) {
			failCount = 0;
			if (i == N) {
				stack->x = a;
				stack->y = b - 1;
				if (mark[stack->y][stack->x] == 0 && maze[stack->y][stack->x] == 0) {
					mark[stack->y][stack->x] = 1;
					push(&head, stack->x, stack->y, top);
					retN = move(maze, mark, row, col, stack, top);
					pop(&head, top);
					stack->x = a;
					stack->y = b;
				}
				else{
					stack->x = a;
					stack->y = b;
					failCount++;
				}
			}
			else if (i == NE) {
				
				stack->x = a + 1;
				stack->y = b - 1;
				if (mark[stack->y][stack->x] == 0 && maze[stack->y][stack->x] == 0) {
					mark[stack->y][stack->x] = 1;
					push(&head, stack->x, stack->y, top);
					retNE = move(maze, mark, row, col, stack, top);
					pop(&head, top);
					stack->x = a;
					stack->y = b;
				}
				else {
					stack->x = a;
					stack->y = b;
					failCount++;
				}
			}
			else if (i == E) {
				stack->x = a + 1;
				stack->y = b;
				if (mark[stack->y][stack->x] == 0 && maze[stack->y][stack->x] == 0) {
					mark[stack->y][stack->x] = 1;
					push(&head, stack->x, stack->y, top);
					retE = move(maze, mark, row, col, stack, top);
					pop(&head, top);
					stack->x = a;
					stack->y = b;
				}
				else {
					stack->x = a;
					stack->y = b;
					failCount++;
				}
			}
			else if (i == SE) {
				stack->x = a + 1;
				stack->y = b + 1;
				if (mark[stack->y][stack->x] == 0 && maze[stack->y][stack->x] == 0) {
					mark[stack->y][stack->x] = 1;
					push(&head, stack->x, stack->y, top);
					retSE = move(maze, mark, row, col, stack, top);
					pop(&head, top);
					stack->x = a;
					stack->y = b;
				}
				else {
					stack->x = a;
					stack->y = b;
					failCount++;
				}
			}
			else if (i == S) {
				stack->x = a;
				stack->y = b + 1;
				if (mark[stack->y][stack->x] == 0 && maze[stack->y][stack->x] == 0) {
					mark[stack->y][stack->x] = 1;
					push(&head, stack->x, stack->y, top);
					retS = move(maze, mark, row, col, stack, top);
					pop(&head, top);
					stack->x = a;
					stack->y = b;
				}
				else {
					stack->x = a;
					stack->y = b;
					failCount++;
				}
			}
			else if (i == SW) {
				stack->x = a - 1;
				stack->y = b + 1;
				if (mark[stack->y][stack->x] == 0 && maze[stack->y][stack->x] == 0) {
					mark[stack->y][stack->x] = 1;
					push(&head, stack->x, stack->y, top);
					retSW = move(maze, mark, row, col, stack, top);
					pop(&head, top);
					stack->x = a;
					stack->y = b;
				}
				else {
					stack->x = a;
					stack->y = b;
					failCount++;
				}
			}
			else if (i == W) {
				stack->x = a - 1;
				stack->y = b;
				if (mark[stack->y][stack->x] == 0 && maze[stack->y][stack->x] == 0) {
					mark[stack->y][stack->x] = 1;
					push(&head, stack->x, stack->y, top);
					retW = move(maze, mark, row, col, stack, top);
					pop(&head, top);
					stack->x = a;
					stack->y = b;
				}
				else {
					stack->x = a;
					stack->y = b;
					failCount++;
				}
			}
			else if (i == NW) {
				stack->x = a - 1;
				stack->y = b - 1;
				if (mark[stack->y][stack->x] == 0 && maze[stack->y][stack->x] == 0) {
					mark[stack->y][stack->x] = 1;
					push(&head, stack->x, stack->y, top);
					retNW = move(maze, mark, row, col, stack, top);
					pop(&head, top);
					stack->x = a;
					stack->y = b;
				}
				else {
					stack->x = a;
					stack->y = b;
					failCount++;
				}
			}
		}
		if(failCount==8) {
			pop(&head, top);
			retsum = 0;
		}
		retsum = retN + retNE + retE + retSE + retS + retSW + retW + retNW;
	}
	mark[b][a] = 0;
	return retsum;
}
