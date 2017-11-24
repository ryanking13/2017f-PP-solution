#include<stdio.h>

int count_one(int num){
    int cnt = 0;
    for(int i = 0; i < 32; i++){
        if(num & (1 << i)){
            cnt++;
        }
    }
    
    return cnt;
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        int d;
        scanf("%d", &d);
        
        int chk = 1;
        for(int j = d-32; j < d; j++ ){
            
            if (j <= 0) continue;
            
            if( (j + count_one(j)) == d ){
                printf("%d\n", j);
                chk = 0;
                break;
            }                
        }
        
        if(chk)
            printf("-1\n");
    }
}