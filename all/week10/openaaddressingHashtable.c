#include<stdio.h>
#include<stdlib.h>
#define M 12
#define DELETED -2
void init(int T[]) {
	for (int i = 0; i < M; i++) {
		T[i] = DELETED;
	}
}
int h(int k, int i) {
	k = k % M;
	if (k == M - 1) {
		k = 0;
	}
	return k + i;
}
int hashSearch(int T[], int k) {
	int i = 0, j;
	while (1) {
		j = h(k, i);
		if (T[j] == k) {
			return j;
		}
		i++;
		if (i == M) {
			return -1;
		}
	}
}
int hashInsert(int T[], int k) {
	int i = 0,j;
	while (1) {
		j = h(k, i);
		if (T[j] == DELETED) {
			T[j] = k;
			return j;
		}
		else {
			i++;
		}
		if (i == M) {
			printf("hash table overflow\n");
			return -1;
		}
	}
}
void printHash(int T[]) {
	printf("hash: ");
	for (int i = 0; i < M; i++) {
		if (T[i] != -2) {
			printf("%d ", T[i]);
		}
	}
	printf("\n");
}
void deleteHash(int T[], int k) {
	int j = hashSearch(T,k);
	if (j != -1) {
		T[j] = DELETED;
	}
	else if (j == -1) {
		printf("there is no %d\n", k);
	}
}
int main() {
	int T[M];
	int i, key,menu;
	init(T);
	while (1) {
		printHash(T);
		printf("1. 추가 2. 삭제 3. 끝\n");
		scanf("%d", &menu);
		if (menu == 3) {
			break;
		}
		switch (menu) {
		case 1: printf("넣을 값: "); scanf("%d", &key); hashInsert(T, key); break;
		case 2: printf("뺄 값: "); scanf("%d", &key); deleteHash(T, key); break;
		}
	}
}
