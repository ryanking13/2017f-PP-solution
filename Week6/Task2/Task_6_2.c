#include <stdio.h>

int bc(int n, int k)
{
    if( n<0 || k<0 || n<k)
        return 0;
    if(k == 0)
        return 1;
    return bc(n-1, k-1) + bc(n-1, k);
}


int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", bc(n, k));    
    return 0;
}
