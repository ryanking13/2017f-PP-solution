#include<stdio.h>

int main(){
	int N;
	int mat1[20][20], mat2[20][20];
	int mat3[20][20] = {0};
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &mat1[i][j]);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &mat2[i][j]);
			
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
				mat3[i][j] += mat1[i][k] * mat2[k][j];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", mat3[i][j]);
		}
		printf("\n");
	}
}
