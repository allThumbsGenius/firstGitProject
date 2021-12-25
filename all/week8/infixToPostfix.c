#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char key;
	int top;
	struct node *next;
}STACK;
int PRECEDENCE(char q) {
	switch (q) {
	case'(': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	}
}
int isNum(char n) {
	switch (n) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '/':
	case '*': return 0;
	}
	return 1;
}
void initStack(STACK *s) {
	s->key = NULL;
	s->next = NULL;
	s->top = -1;
}
void printStack(STACK *s) {
	while (s->next != NULL) {
		s = s->next;
		printf("%c ", s->key);
	}
	printf("\n");
}
void PUSH(STACK *s, char k) {
	STACK *temp;
	temp = (STACK *)malloc(sizeof(STACK));
	while (s->next != NULL) {
		s = s->next;
	}
	temp->key = k;
	temp->next = NULL;
	temp->top = s->top + 1;
	s->next = temp;
}
char POP(STACK *s) {
	char ret;
	while (s->next->next != NULL) {
		s = s->next;
	}
	ret=s->next->key;
	s->next = NULL;
	return ret;
}
char last(STACK *s) {
	while (s->next != NULL) {
		s = s->next;
	}
	return s->key;
}
int STACK_EMPTY(STACK *s) {
	while (s->next != NULL) {
		s = s->next;
	}
	return (s->top == -1);
}
void POSTFIX(STACK *s, STACK *out ,char in[], int n) {
	int i,q;
	for (i = 0; i < n; i++) {
		q = in[i];
		if (isNum(q)) {
			PUSH(out, q);
		}
		else if (q == '(') {
			PUSH(s, q);
		}
		else if (q == ')') {
			while (last(s) != '(') {
				PUSH(out, POP(s));
			}
			POP(s);
		}
		else {
			while (PRECEDENCE(q) <= PRECEDENCE(last(s))) {
				PUSH(out, POP(s));
			}
			PUSH(s, q);
		}
	}
	while (!STACK_EMPTY(s)) {
		PUSH(out, POP(s));
	}
}
int main() {
	char A[] = "1*2*3+9-7*2";
	STACK *stack;
	STACK *output;
	stack = (STACK *)malloc(sizeof(STACK));
	output = (STACK *)malloc(sizeof(STACK));
	initStack(stack);
	initStack(output);
	POSTFIX(stack, output, A, sizeof(A) - 1);
	printStack(output);
}
