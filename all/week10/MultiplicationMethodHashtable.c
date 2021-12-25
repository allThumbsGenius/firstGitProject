#include<stdio.h>
#include<stdlib.h>
#define M 8
typedef struct _node{
	int key;
	struct _node *next;
}node;

void init(node *T[], int size) {
	for (int i = 0; i < size; i++) {
		T[i] = (node*)malloc(sizeof(node));
		T[i]->next = NULL;
		T[i]->key = NULL;
	}
}
int h(int k) {
	int i;
	int countKbit=0;
	int topbit[3] = { 0 };//M=8이므로 p=3, 0<= h(k) < M
	int s = 13;//내가 선택한 s
	int ks, wow=1, awsome, sum=0;
	ks = (k*s);
	while (k > 0) {
		k >>= 1;
		countKbit++;
	}
	for (i = 0; i <countKbit; i++) {
		wow *= 2;
	}
	printf("2^w: %d\n", wow);
	awsome = ((ks) % wow);
	printf("ks mod 2^w: %d\n", awsome);
	while (awsome>M-1) {
		awsome >>= 1;
	}
	for (i = sizeof(topbit) / 4-1; i >=0 ; i--) {
		topbit[i] = awsome & 1;
		awsome >>= 1;
	}

	printf("topbit: ");
	for (i = 0; i < sizeof(topbit) / 4; i++) {
		printf("%d", topbit[i]);
	}
	printf("\n");
	for (i = 0; i < sizeof(topbit) / 4; i++) {
		sum += topbit[i] << (sizeof(topbit)/4-1-i);
	}
	return sum;
}
void hashInsert(node * T[], int x) {
	node *temp;
	node *temp2=T[h(x)];
	temp = (node*)malloc(sizeof(node));
	temp->key = x;
	temp->next = NULL;
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}
	temp2->next = temp;
}
void hashSearch(node * T[], int x) {
	node *temp = T[h(x)];
	while (temp->key != x && temp->next !=NULL) {
		temp = temp->next;
	}
	if (temp->key == x) {
		printf("find: %d\n", temp->key);
	}
	else {
		printf("there is no %d\n", x);
	}
}
void hashPrint(node * T[], int x) {
	printf("T[%d]: ", x);
	node *temp = T[x];
	while (temp->next != NULL) {
		temp = temp->next;
		printf("%d->", temp->key);
	}
	printf("\n");
}

void hashDelete(node * T[], int x) {
	node *temp=T[h(x)];
	node *delete;
	while (temp->next->key != x) {
		temp = temp->next;
	}
	delete=temp->next;
	temp->next = temp->next->next;
	free(delete);
}
int main() {
	int i, key,menu;
	node *T[M];//{node *T[0] node*T[1], ...}
	init(T, M);
	while (1) {
		for (i = 0; i < M; i++) {
			hashPrint(T, i);
		}
		printf("1. 추가 2. 삭제 3. 끝\n");
		scanf("%d", &menu);
		if (menu == 3) {
			break;
		}
		switch (menu) {
		case 1: printf("넣을 값: "); scanf("%d", &key); hashInsert(T, key); break;
		case 2: printf("뺄 값: "); scanf("%d", &key); hashDelete(T, key); break;
		}
	}
}
