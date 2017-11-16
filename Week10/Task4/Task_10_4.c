#include<stdio.h>

long long max(long long a, long long b){
    if(a>b) return a;
    else return b;
}

long long min (long long a, long long b){
    if(a>b) return b;
    else return a;
}

int main(){
    int N;
    scanf("%d", &N);
    
    long long l=-1000000005;
    long long r=1000000005;
    long long t=1000000005;
    long long b=-1000000005;
    
    int no_overlap = 0;
    for(int i = 0; i < N; i++){
        long long x1, x2, y1, y2;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        
        // if overlapping 
        if( !((x1 >= r) || (x2 <= l) || (y1 >= t) || ( y2 <= b)) ){
            l = max(l, x1);
            r = min(r, x2);
            b = max(b, y1);
            t = min(t, y2);
        }
        else{
            no_overlap = 1;
        }
        
        if(no_overlap){
            printf("0\n");
        } else {
            printf("%lld\n", (r-l)*(t-b));
        }
        
    }
}