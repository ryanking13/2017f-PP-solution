#include <stdio.h>
 
int main()
{
    int n, q, x, i, j, score[1000] = {0}, rank[1000] = {0};
 
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &score[i]);
 
    for(i = 0; i < n; i++)
    {
        rank[i] = 1;
        for(j = 0; j < n; j++)
            if(score[i] < score[j]) rank[i]++;
    }
     
 
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        scanf("%d", &x);
        for(j = 0; j < n; j++)
        {
            if(rank[j] == x)
            {
                printf("%d\n", score[j]);
                break;
            }
        }
    }
 
    return 0;
}