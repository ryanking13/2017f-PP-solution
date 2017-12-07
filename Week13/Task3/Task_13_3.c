#include <stdio.h>

long long max(long long a, long long b){
	if( a > b ) return a;
	return b;
}

long long price[100500];
long long mx[100500];
int N;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%lld",&price[i]);

	for(int i=N;i>=1;i--){
		mx[i] = max( price[i] , mx[i+1] );
	}
	long long ans = 0;
	for(int i=1;i<=N;i++){
		if ( mx[i+1] > price[i] ) ans += mx[i+1]-price[i];
	}
	printf("%lld\n",ans);
}