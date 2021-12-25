#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct node{
	struct node *prev;
	element key;
	struct node *next;
}NODE;
void initList(NODE *n) {
	n->prev = NULL;
	n->key = NULL;
	n->next = NULL;
}
void showNode(NODE *n) {
	printf("LIST: ");
	while (n->next != NULL) {
		n = n->next;
		printf("%d ", n->key);
	}
	printf("\n");
}
void addNode(NODE *n) {
	element keyNum;
	NODE *temp;

	temp = (NODE *)malloc(sizeof(NODE));

	printf("넣을 값 입력: ");
	scanf("%d", &keyNum);
	while (n->next != NULL) {
		n = n->next;
	}
	temp->key = keyNum;
	temp->prev = n;
	temp->next = NULL;
	n->next = temp;
}
NODE *listSearch(NODE *n, int k) {
	while (n != NULL && n->key != k) {
		n = n->next;
	}
	printf("find: %d\n", n->key);
	return n;
}
void listInsert(NODE *head, NODE *x) {
	printf("\ninsert %d head of list\n\n", x->key);
	x->next = head->next;
	head->next->prev = x;
	head->next = x;
	x->prev = head;
}
void listDelete(NODE *n) {
	int k;
	printf("무엇을 지울까요?: ");
	scanf("%d", &k);

	n = listSearch(n, k);
	n->prev->next = n->next;
	if (n->next != NULL) {
		n->next->prev = n->prev;
	}
}
int main() {
	NODE *head;
	NODE *insert;
	int i;
	head = (NODE *)malloc(sizeof(NODE));

	insert = (NODE *)malloc(sizeof(NODE));
	insert->key = 7;

	initList(head);
	for (i = 0; i < 4; i++) {
		addNode(head);
	}
	showNode(head);
	listInsert(head, insert);
	showNode(head);
	listDelete(head);
	showNode(head);
}


