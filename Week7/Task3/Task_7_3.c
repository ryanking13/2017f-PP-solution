#include <stdio.h>

int array_cmp(int N, int* A, int* B){
	int i;
	for(i=0;i<N;i++){
		if( A[i] < B[i] ) return 1;
		else if( A[i] > B[i] ) return -1;
	}
	return 0;
}