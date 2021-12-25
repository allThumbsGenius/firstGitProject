#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randomNum(int p,int r) {
	srand(time(NULL));
	return rand() % (r - p) + p+1;
}
int partition(int A[], int p, int r) {
	int j, i, x;
	int temp;
	x = A[r];
	i = p - 1;
	for (j = p; j <= r - 1; j++) {
		if (A[j] <= x) {
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[r];
	A[r] = A[i + 1];
	A[i + 1] = temp;
	return i + 1;
}
int randomized_partition(int A[], int p, int r) {
	int i, temp;
	i = randomNum(p, r);
	temp = A[i];
	A[i] = A[r];
	A[r] = temp;
	return partition(A, p, r);
}

void randomized_quicksort(int A[], int p, int r) {
	int q;
	if (p < r) {
		q = randomized_partition(A, p, r);
		randomized_quicksort(A, p, q - 1);
		randomized_quicksort(A, q + 1, r);
	}

}
void quicksort(int A[], int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}
int main() {
	int A[] = { 8,1,6,4,0,3,9,5 };
	int B[] = { 8,1,6,4,0,3,9,5 };
	quicksort(A, 0, sizeof(A) / 4 - 1);
	randomized_quicksort(B, 0, sizeof(B) / 4 - 1);
	for (int i = 0; i < sizeof(A) / 4; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	for (int i = 0; i < sizeof(B) / 4; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");
}
