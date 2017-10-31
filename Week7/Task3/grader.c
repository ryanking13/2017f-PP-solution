#include <stdio.h>
#include "Task_7_3.h"
/*
int array_cmp(int N, int* A, int* B){
	int i;
	for(i=0;i<N;i++){
		if( A[i] < B[i] ) return 1;
		else if( A[i] > B[i] ) return -1;
	}
	return 0;
}
*/
int main(){
	int A[10050], B[10050];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<n;i++) scanf("%d",&B[i]);
	printf("%d",array_cmp(n,A,B));
}