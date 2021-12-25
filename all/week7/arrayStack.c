#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 10
int stackFull(int *top) {
	return (*top == MAXNUM);

}
int stacckEmpty(int *top) {
	return (*top == -1);
}
void push(int S[], int x, int *top) {
	if (stackFull(top)) {
		printf("꽉참\n");
	}
	else {
		S[++*top] = x;
	}
}
int pop(int S[], int *top) {
	int last;
	if (stacckEmpty(top)) {
		return -1;
	}
	else {
		return S[--*top+1];
	}
}

int main() {
	int stack[MAXNUM];
	int top=-1;
	int count = 0;
	int select, x,i, popNum;

	while (1) {
		printf("1. push\n2. pop\n\n");
		printf("할 동작: ");
		scanf("%d", &select);
		if(select !=1 && select !=2){
			break;
		}
		switch (select) {
		case 1: printf("넣을 값: "); scanf("%d", &x); push(stack, x, &top); count++; break;
		case 2: popNum = pop(stack, &top); if (popNum == -1) { printf("스택 부족\n"); }
				else { printf("pop: %d\n", popNum); count--; } break;
		}

		printf("\nstack: ");
		for (i = 0; i < count; i++) {
			printf("%d ", stack[i]);
		}
		printf("\n-----------------------\n");
	}
	free(stack);
}
