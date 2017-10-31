#include<stdio.h>

int main(void)
{
    char* str = 
        "\
        P-P-A-P\
        I have a pen, I have a apple\
        Uh! Apple-Pen!\
        I have a pen, I have pineapple\
        Uh! Pineapple-Pen!\
        Apple-Pen, Pineapple-Pen\
        Uh! Pen-Pineapple-Apple-Pen\
        Pen-Pineapple-Apple-Pen\
        ";
    char pattern[2];
    scanf("%s", pattern);
    
    int indexCount = 0;
    int count = 0;
    while(str[indexCount]!='\0')
    {
        if(str[indexCount]==pattern[0] && str[indexCount+1]==pattern[1])
        {
            count++;
        }
        indexCount++;
    }

    printf("%d\n", count);
    
    return 0;

}
