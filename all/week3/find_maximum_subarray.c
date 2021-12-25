#include<stdio.h>
void findMaxCrossingSubarray(int A[], int low, int mid, int high, int *ret_low, int *ret_high, int *ret_sum){
	int sum, left_sum, right_sum;
	int i, j;
	sum = 0;
	for (i = mid; i >= low; i--){
		sum += A[i];
		if (i==mid || sum > left_sum){
			left_sum = sum;
			*ret_low = i;
		}
	}
	sum = 0;
	for (j = mid + 1; j <= high; j++){
		sum += A[j];
		if (j == mid + 1 || sum > right_sum){
			right_sum = sum;
			*ret_high = j;
		}
	}
	*ret_sum = left_sum + right_sum;
}
void findMaximunSubArray(int A[], int low, int high, int *ret_low, int *ret_high, int *ret_sum){
	int mid;
	int left_low, left_high, left_sum;
	int right_low, right_high, right_sum;
	int cross_low, cross_high, cross_sum;
	if (high == low){
		*ret_low = low;
		*ret_high = high;
		*ret_sum = A[low];
	}
	else{
		mid = (low + high) / 2;
		findMaximunSubArray(A, low, mid, &left_low, &left_high, &left_sum);
		findMaximunSubArray(A, mid+1, high, &right_low, &right_high, &right_sum);
		findMaxCrossingSubarray(A, low, mid, high, &cross_low, &cross_high, &cross_sum);
		if (left_sum >= right_sum && left_sum >= cross_sum){
			*ret_low = left_low;
			*ret_high = left_high;
			*ret_sum = left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum){
			*ret_low = right_low;
			*ret_high = right_high;
			*ret_sum = right_sum;
		}
		else{
			*ret_low = cross_low;
			*ret_high = cross_high;
			*ret_sum = cross_sum;
		}
	}
}
int main(){
	int A[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	int left, right, sum;

	findMaximunSubArray(A, 0, 15, &left, &right, &sum);
	printf("%d %d %d\n", left, right, sum);
}
