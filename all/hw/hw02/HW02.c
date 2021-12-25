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

void build_max_heap(int A[], int n) {
	int i;
	for (i = n / 2; i >= 0; i--) {
		maxHeapify(A, i, n);
	}
}

void max_heap_append(int A[], int p, int q){
	int temp, i;
	for(i=p;i<=q;i++){
		if(i>0 && A[i]>A[parent(i)]){
			temp=A[parent(i)];
			A[parent(i)]=A[i];
			A[i]=temp;
			max_heap_append(A,parent(i),q);
		}		
	}
}
