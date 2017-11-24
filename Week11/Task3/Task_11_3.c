#include<stdio.h>

int arr1[100000];
int arr2[100000];
int merged[200000];

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    
    for(int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);
    
    int ni = 0;
    int mi = 0;
    int idx = 0;
    while(ni < n && mi < m){
        if(arr1[ni] <= arr2[mi])
            merged[idx++] = arr1[ni++];
        
        else
            merged[idx++] = arr2[mi++];
    }
    
    while(ni < n)
        merged[idx++] = arr1[ni++];
    
    while(mi < m)
        merged[idx++] = arr2[mi++];
    
    for(int i = 0; i < idx; i++){
        printf("%d ", merged[i]);
    }
}