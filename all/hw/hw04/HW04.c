#include<stdio.h>
#include<stdlib.h>
int dynamic_counting_sort(int A[], int B[], int n) {
	int **C;
	int j, i;
	int *whatNum;
	int letscount = 0, sum=0;
	int key;

	whatNum = (int *)malloc(1 * sizeof(int));

	//compare and make new space for new number
	for (i = 0; i<n; i++) {
		for (j = 0; j<=letscount; j++) {
			if (A[i] == whatNum[j]) {
				break;
			}
		}
		if (j == letscount+1) {
			whatNum[letscount] = A[i];
			letscount++;
			whatNum = realloc(whatNum, (letscount+1) * sizeof(int));
		}
	}
	//end
	//insertion sort
	for (j = 0; j < letscount; j++) {
		key = whatNum[j];
		i = j - 1;
		while (i >= 0 && whatNum[i]>key) {
			whatNum[i + 1] = whatNum[i];
			i = i - 1;
		}
	whatNum[i + 1] = key;
	}
	//end

	//make a two dimension array
	C = (int **)malloc(letscount * 2 * sizeof(int*));
	for (i = 0; i < letscount; i++) {
		C[i] = (int *)calloc(2, sizeof(int));
	}
	//end

	//insert in column 1 form array "A"'s number
	for (i = 0; i < letscount; i++) {
		C[i][0] = whatNum[i];
	}
	//end

	//counting sort start
	//count all numbers
	for (i = 0; i < n; i++) {
		for (j = 0; j < letscount; j++) {
			if (A[i] == C[j][0]) {
				C[j][1]++;
			}
		}
	}
	//end
	//decide starting index from sum
	for (i = 1; i < letscount; i++) {
		C[i][1] = C[i][1]+C[i - 1][1];
	}
	//end
	//put sorted array to array "B"
	for (i = n-1; i >=0; i--) {
		for (j = 0; j < letscount; j++) {
			if (A[i] == C[j][0]) {
				B[C[j][1] - 1] = A[i];
				C[j][1]--;
			}
		}
	}
	//end
	//return sum of left C[i][1]
	for (i = 0; i < letscount; i++) {
		sum += C[i][1];
	}
	free(whatNum);
	free(C);
	return sum;
}
