#include<stdio.h>

int main(){
	int na, nb;
	int a[1000], b[1000];
	int i, j;
	int cnt = 0;
	int idxs[1000] = {0};
	
	scanf("%d", &na);
	
	for(i=0; i<na; i++)
		scanf("%d", &a[i]);
		
	scanf("%d", &nb);
	
	for(i=0; i<nb; i++)
		scanf("%d", &b[i]);
	
	for(i=0; i<na-nb+1; i++){
		int chk = 1;
		for(j=0; j<nb; j++){
			if(a[i+j] != b[j]){
				chk = 0;
				break;
			}
		}
		
		if(chk){
			cnt++;
			idxs[i] = 1;
		}
	}
	
	printf("%d\n", cnt);
	for(i=0; i<na; i++){
		if(idxs[i]){
			printf("%d ", i);
		}
	}
}
