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
int hybridsort(int A[], int p, int q, int t){
	int i,j,key;
	int pivot, left, right;
	if(q-p<t){
		for(j=p;j<=q;j++){
        	key=A[j];
        	i=j-1;
        	while(i>=0 && A[i]>key){
            	A[i+1]=A[i];
            	i=i-1;
        	}
        A[i+1]=key;
		}
		return 1;
    }
	else{
		pivot = partition(A, p, q);
		left=hybridsort(A, p, pivot - 1,t);
		right=hybridsort(A, pivot + 1, q,t);
		return left+right;
	}
}
