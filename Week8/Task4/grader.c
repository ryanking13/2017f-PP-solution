#include<stdio.h>
#include<stdlib.h>
#include "Task_8_4.h"
/*
int* sort_array(int n, int* arr){
	// you should implement this function

	int* p = (int*)malloc(sizeof(int) * n);
	int i,j;

	for(i=0;i<n;i++){
		p[i] = arr[i];
	}

	for(i=0;i<n;i++){
		for(j=0 ; j < n-i-1 ; j++){
			if(p[j] < p[j+1]){
				int temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	return p;
}

*/

int main(){
	int n;
	int A[10050];
	scanf("%d",&n);
	int i;

	for(i=0;i<n;i++) scanf("%d",&A[i]);

	int*arr = sort_array(n,A);

	for(i=0; i<n ; i++ ){
	printf("%d ",arr[i]);
	}
}