#include<stdio.h>
#include<stdlib.h>
typedef int element;//편하게 데이터의 형을 바꾸어 줄 수 있다.
typedef struct {
	element *data;
	int top;
}stackType;
//s->data == (*s).data

int stackEmpty(stackType *s) {
	return (s->top == -1);
}
void initStack(stackType *s) {
	s->data = (element *)malloc(0 * 4);
	s->top = -1;
}
void pushStack(stackType *s, int x) {
	s->data = (element *)realloc(s->data, (s->top + 2) * 4);
	s->data[++s->top] = x;
}
int popStack(stackType *s) {
	element *temp;
	int i, last;
	if (stackEmpty(s)) {
		return -1;
	}
	else {
		temp = (element *)malloc((s->top) * 4);
		for (i = 0; i < s->top; i++) {
			temp[i] = s->data[i];
		}
		last = s->data[s->top--];
		s->data = temp;
		return last;
	}
}
int main() {
	stackType stack1;
	int select, popNum, x, i;

	initStack(&stack1);

	while (1) {
		printf("1. push\n2. pop\n\n");
		printf("할 동작: ");
		scanf("%d", &select);
		if(select!=1 && select !=2){
			break;
		}
		switch (select) {
		case 1: printf("넣을 값: "); scanf("%d", &x); pushStack(&stack1, x); break;
		case 2: popNum = popStack(&stack1); if (popNum == -1) { printf("스택 부족\n"); }
				else { printf("\npop: %d\n", popNum); } break;
		}

		printf("\nstack: ");
		for (i = 0; i <= stack1.top; i++) {
			printf("%d ", stack1.data[i]);
		}
		printf("\n-----------------------\n");
	}
	free(stack1.data);
}
