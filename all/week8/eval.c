#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int key;
	struct node* next;
}stack;
int isNum(char n) {
	switch (n) {
	case '+':
	case '-':
	case '/':
	case '*': return 0;
	}
	return 1;

}
void initStack(stack *s) {
	s->key = NULL;
	s->next = NULL;
}
void PUSH(stack *s, int n) {
	stack *temp;
	temp = (stack *)malloc(sizeof(stack));
	while (s->next != NULL) {
		s = s->next;
	}
	temp->key = n;
	temp->next = NULL;
	s->next = temp;
}
int POP(stack *s) {
	int ret;
	while (s->next->next!= NULL) {
		s = s->next;
	}
	ret = s->next->key;
	s->next = NULL;
	return ret;
}
void printStack(stack *s) {
	printf("stack: ");
	while (s->next != NULL) {
		s = s->next;
		printf("%d->", s->key);
	}
	printf("\n");
}
int EVAL(stack *s, char Post[], int n) {
	int i;
	int q;
	int x, y;
	for (i = 0; i < n; i++) {
		q = Post[i];
		if (isNum(q)) {
			PUSH(s, q-48);
		}
		else {
			x = POP(s);
			y = POP(s);
			if (q == '+') {
				PUSH(s, y + x);
			}
			else if(q == '-') {
				PUSH(s, y - x);
			}
			else if (q == '*') {
				PUSH(s, y * x);
			}
			else if (q == '/') {
				PUSH(s, y / x);
			}
		}
	}
	return POP(s);
}

int main() {
	char A[] = "62/3-42*+";
	stack *eval;
	eval = (stack *)malloc(sizeof(stack));
	initStack(eval);
	printf("%d\n", EVAL(eval, A, sizeof(A)-1));
}
