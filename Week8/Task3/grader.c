#include<stdio.h>
#include<stdlib.h>
#include "Task_8_3.h"
/*
int* number_malloc(int n){
	int* a = (int*)malloc(n*sizeof(int));
	int i;
	for(i = 0 ; i < n ; i++ ){
		a[i] = i+1;
	}

	return a;
}
*/

int main(){
	int n;
	scanf("%d",&n);
	int*arr = number_malloc(n);
	int i;
	for(i=0; i<n ; i++ ){
	printf("%d ",arr[i]);
}
}