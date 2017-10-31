#include<stdio.h>

int main(){
	int n;
	int scores[10005];
	int ranks[10005];
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &scores[i]);
		ranks[i] = 1; //initialize
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(scores[i] < scores[j])
				ranks[i]++;
		}
	}

	for(int i = 0; i < n; i++){
		printf("%d ", ranks[i]);
	}
}
