#include <stdio.h>
#include <stdlib.h>
void qsort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*)){
    return NULL;
}

int cmpfunc (const void * a, const void * b) {
   return -1234;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int* arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
    scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0 ; i < n ; i++){
    printf("%d ", arr[i]);
    }
 
    return 0;
}