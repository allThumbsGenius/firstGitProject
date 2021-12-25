#include<stdio.h>
#include<stdlib.h>
int poww(int a, int b){
	int ret=1;
	for(int i=0;i<b;i++){
		ret*=a;
	}
	return ret;
}
void coountingSortRadix(int A[], int B[], int k, int l, int Alength) {
	int *C;
	int j,i;

	C = (int *)calloc(k+1, sizeof(int));

	for (j = 0; j < Alength; j++) {
		C[((int)(A[j]/poww(10,l)))%10]++;
	}
	for (i = 1; i <= k; i++) {
		C[i] += C[i - 1];
	}
	for (j = Alength-1; j >= 0; j--) {
		B[C[((int)(A[j] / poww(10, l))) % 10]-1] = A[j];
		C[((int)(A[j] / poww(10, l))) % 10]--;
	}
	free(C);
}

void radixSort(int A[], int d, int Alength) {
	int i,j;
	int *B;
	B = (int *)malloc(Alength*sizeof(int));

	for (i = 0; i < d; i++) {
		coountingSortRadix(A, B, 9, i, Alength);
		for (j = 0; j < Alength; j++) {
			A[j] = B[j];
		}
	}
	free(B);
}

int main() {
	int A[] = { 329,457,657,839,436,720,355 };

	radixSort(A, 3, sizeof(A) / 4);
	
	for (int i = 0; i < sizeof(A)/4; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}
