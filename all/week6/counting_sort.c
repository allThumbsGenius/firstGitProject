#include<stdio.h>
#include<stdlib.h>
int findMax(int A[], int Alength) {
	int max=0,i;
	for (i = 0; i < Alength; i++) {
		if (max < A[i]) {
			max = A[i];
		}
	}
	return max;
}
void coountingSort(int A[], int B[], int k, int Alength) {
	int *C;
	int j,i;

	C = (int *)calloc(k+1, sizeof(int));

	for (j = 0; j < Alength; j++) {
		C[A[j]]++;
	}
	for (i = 1; i <= k; i++) {
		C[i] += C[i - 1];
	}
	for (j = Alength-1; j >= 0; j--) {
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}
	free(C);
}

int main() {
	int A[] = { 2,5,3,0,2,3,0,3 };
	int *B;
	int max;

	B = (int *)malloc(sizeof(A));
	max=findMax(A, sizeof(A) / 4);

	coountingSort(A, B, max, sizeof(A)/4);
	
	for (int i = 0; i < sizeof(A)/4; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");
	free(B);

	return 0;
}
