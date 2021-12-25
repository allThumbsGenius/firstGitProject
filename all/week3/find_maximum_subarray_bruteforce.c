#include<stdio.h>
void findMaximumSubarrayBruteForce(int A[], int low, int high,int *ret_left,int *ret_right,int *ret_sum){
	int i, j;
	int left,right,sum;

	for (i = low; i <= high; i++){
		sum = 0;
		for (j = i; j <= high; j++){
			sum += A[j];
			if (j == low || sum > *ret_sum){
				*ret_left = i;
				*ret_right = j;
				*ret_sum = sum;
			}
		}
	}
}
int main(){
	int A[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	int left, right, sum;

	findMaximumSubarrayBruteForce(A, 0, 15, &left, &right, &sum);
	printf("%d %d %d\n", left, right, sum);
}
