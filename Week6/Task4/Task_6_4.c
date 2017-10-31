#include <stdio.h>

int abs(int x){
	return (x<0)?-x:x;
}

int mdist(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}
int N;
int x[1050], y[1050];
int main(){
	scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++) scanf("%d%d",x+i,y+i);
	int mn = 987654321, mx = -1;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if( i == j ) continue;
			int d = mdist(x[i],y[i],x[j],y[j]);
			if( d < mn ) mn = d;
			if( d > mx ) mx = d;
		}
	}
	printf("%d\n%d\n",mn,mx);
}