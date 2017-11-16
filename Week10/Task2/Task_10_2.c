#include <stdio.h>

int main(void){

	int n;
	scanf("%d",&n);
	int arr[n];
	int b[n];

	for(int i = 0 ; i < n ; i++){
		scanf("%d",&arr[i]); 
	}

	int max = arr[0];
	int start = 0;
	int end = 0;
	int startI = 0;

	if(n < 1000){
		printf("small\n");
	for(int i = 0 ; i < n; i++){
		int sum = 0;
		for(int j = i ; j < n; j++){
			sum += arr[j];
		if(sum > max){
			max = sum;
			start = i;
			end = j;
		}
		}
	}
	}
	else{
		printf("big\n");
		b[0] = arr[0];	
		for(int i = 1; i < n ;i++){
			if(b[i-1]+arr[i] > arr[i]){
				b[i] = b[i-1]+arr[i];
			}else {
				startI = i;
				b[i] = arr[i];
			}

			if(b[i] > max){
				start = startI;
				max = b[i];
				end = i;
			}

		}

	}
	printf("%d,%d\n",start,end);
	printf("%d",max);
	 return 0;
}
