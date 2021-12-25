#include<stdio.h>
void allocateObject(int next[], int key[], int prev[], int *free, int *L) {
	int x, temp;
	if (*free == -1) {
		printf("out of space\n");
	}
	else {
		printf("넣을 값: ");
		scanf("%d", &x);
		//
		temp = next[*free];
		prev[*L] = *free;
		//
		next[*free]=*L;
		*L = *free;
		key[*free] = x;
		prev[*free] = -1;
		//
		*free = temp;
	}
}
void freeObject(int next[], int key[], int prev[], int *free, int *L) {
	int x, tempL=*L;
	printf("뺄 값: ");
	scanf("%d", &x);
	while (key[tempL] != x) {
		if (next[tempL] == -1) {
			printf("no data %x\n", x);
			break;
		}
		tempL = next[tempL];
	}
	next[tempL] = *free;
	key[tempL] = -1;
	prev[tempL] = -1;
	*free = tempL;
}
void printL(int next[], int key[], int prev[]) {
	for (int i = 0; i < 8; i++) {
		if (next[i] == -1) {
			printf("| /|");
		}
		else {
			printf("|%2d|", next[i]);
		}
	}
	printf("\n");
	for (int i = 0; i < 8; i++) {
		if (key[i] == -1) {
			printf("| /|");
		}
		else {
			printf("|%2d|", key[i]);
		}
	}
	printf("\n");
	for (int i = 0; i < 8; i++) {
		if (prev[i] == -1) {
			printf("| /|");
		}
		else {
			printf("|%2d|", prev[i]);
		}
	}
	printf("\n");
}
int main() {
	int next[8] = {-1,2, -1, 7, 1, 0, 4, 5};
	int key[8] = {-1, 4, 1, -1, 16, -1, 9, -1};
	int prev[8] = {-1, 4, 1, -1, 6, -1, -1, -1};
	int L,free;
	free = 3;
	L = 6;
	printL(next, key, prev);
	allocateObject(next, key, prev, &free, &L);
	printL(next, key, prev);
	freeObject(next, key, prev, &free, &L);
	printL(next, key, prev);
}
