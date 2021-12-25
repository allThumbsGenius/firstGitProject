#include<stdio.h>
int left(int i) {
	return 2*i+1;
}
int right(int i) {
	return 2 * i + 2;
}
int parent(int i) {
	return (i-1) / 2;
}

void maxHeapify(int A[], int i, int n) {
	int l, r,temp;
	int largest;
	l = left(i);
	r = right(i);

	if (l <= n && A[l] > A[i]) {//왼쪽부터 비교 후 오른쪽 비교
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <=n && A[r] > A[largest]) {
		largest = r;
	}//여기까지 비교

	if (largest != i) {//인덱스 i의 값이 제일 크지 않다면
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A, largest, n);
	}
}

void buildMaxHeap(int A[], int n) {
	int i;
	for (i = n / 2; i >= 0; i--) {
		maxHeapify(A, i, n);
		//leaf 노드는 이미 max_heap하므로 \
		leaf노드 바로 위에서 시작하여 max_heap하게\
		만들어 준다
	}
}

void heapSort(int A[], int n) {
	int i, temp;

	buildMaxHeap(A, n);
	
	for (i = n; i >= 1; i--) {
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		maxHeapify(A, 0, i - 1);
		//바꾸고 heapfify, 바꾸고 heapify
	}
}
int main() {
	int A[] = { 4,1,3,2,16,9,10,14,8,7 };
	heapSort(A, sizeof(A) / 4-1);

	for (int i = 0; i < sizeof(A) / 4; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}
