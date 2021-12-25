#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int key;
	int sateliteData;
}node;

node *directAddressSeatch(node *T[], int k) {
	return T[k];
}
void direcctAddressInsert(node *T[], int x) {
	node *temp;
	temp = (node *)malloc(sizeof(node));
	T[x] = temp;
	T[x]->key = x;
}
void directAddressDelete(node *T[], int x) {
	T[x] = NULL;
	
}
void init(node *T[], int size) {
	for (int i = 0; i < size; i++) {
		T[i] = NULL;
	}
}
int main() {
	int U[] = { 1,2,5,8,9,10 };
	node *T[11];
	init(T, 11);
	for (int i = 0; i < sizeof(U) / 4; i++) {
		direcctAddressInsert(T, U[i]);
	}
	
	for (int i = 0; i < sizeof(U) / 4; i++) {
		printf("%d\n", directAddressSeatch(T, U[i])->key);
	}

	directAddressDelete(T, U[3]);
	
	for (int i = 0; i <11; i++) {
		if (T[i] == NULL) {
			printf("NULL\n");
		}
		else {
			printf("%d\n", T[i]->key);
		}
	}
}
