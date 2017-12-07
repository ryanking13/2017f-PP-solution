#include <stdio.h>

int a[1001][1001];

int main()
{
    int n;
    scanf("%d", &n);
    
    int p = 0, q = n - 1, x = n * n;
    while(p <= q)
    {
        for(int i = p; i < q; i++) a[p][i] = x--;
        for(int i = p; i < q; i++) a[i][q] = x--;
        for(int i = q; i > p; i--) a[q][i] = x--;
        for(int i = q; i > p; i--) a[i][p] = x--;

        q--;
        p++;
        
        if(p == q) a[p][q] = x;
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i][i];
        sum += a[n - 1 - i][i];
    }
    sum--;

    printf("%d\n", sum);
    return 0;
}
