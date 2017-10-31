#include <stdio.h>

int main(){
	long long int fibo[1050];
    
	fibo[1] = 1; 
    fibo[2] = 1;
    
	int n; 
    scanf("%d",&n);
    
	for(int i=3;i<=n;i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
	printf("%lld",fibo[n]);
}