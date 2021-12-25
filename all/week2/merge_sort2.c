#include<stdio.h>
#include<stdlib.h>
void merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L, *R;
	int i, j, k,l, max=0;
	L = (int *)malloc(4 * n1 + 4);
	R = (int *)malloc(4 * n2 + 4);
	for (i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = A[q + j + 1];
	}
	for (l = 0; l <r+1 ; l++){
		if (max <= A[l]){
			max = A[l];
		}
	}
	L[i] = max+1;
	R[i] = max+1;
	i = 0; j = 0;
	for (k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
	free(L);
	free(R);
}

void mergeSort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	int wow[8] = { 2, 4, 5, 7, 1, 2, 3, 6 };
	mergeSort(wow, 0, 7);
	for (int i = 0; i < 8; i++) {
		printf("%d ", wow[i]);
	}
	printf("\n");
	return 0;
}
