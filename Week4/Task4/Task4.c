#include <stdio.h>

int main()
{
    char str[1000] = {0};
    int len, a, b;
    scanf("%d %s", &len, str);
    
    for(a = 0, b = len - 1; a <= b; a++, b--)
    {
        if(str[a] != str[b])
        {
            printf("False\n");
            return 0;
        }
    }
    printf("True\n");
    return 0;
}