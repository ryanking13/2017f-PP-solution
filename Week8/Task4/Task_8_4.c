// Week8 Task4
// Correct Answer

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int* sort_array(int n, int* arr){
	int i,j;
	int* res = (int*) malloc( sizeof(int) * n );

	for(i=0;i<n;i++){
		res[i] = arr[i];
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if( res[i] < res[j] ){
				swap( &res[i], &res[j] );
			}
		}
	}
	
	return res;
}