#include <stdio.h>
#include <stdlib.h>

int* number_malloc(int n){
	int* a = (int*)malloc(n*sizeof(int));
	int i;
	for(i = 0 ; i < n ; i++ ){
		a[i] = i+1;
	}

	return a;
}
