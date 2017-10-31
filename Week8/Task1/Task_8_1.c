#include <ctype.h>
#include <stdio.h>

int main()
{
    int i = 0;
    char str[100];
    while(scanf("%s", str) != EOF)
    {
        i++;
    }
    printf("%d\n", i);
    return 0;
}
