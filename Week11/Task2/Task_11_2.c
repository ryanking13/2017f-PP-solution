#include<stdio.h>
#include<stdlib.h>

int main(){

    char inp[10];
    int stack[1005];
    int top = 0;
    
    while ( (scanf("%s", inp)) != EOF ) {
        if( inp[0] >= '0' && inp[0] <= '9' ){
            stack[top++] = atoi(inp);
        }
        else{
            char op = inp[0];
            int a = stack[top-2];
            int b = stack[top-1];
            top -= 1;
            
            switch(op){
                case '+':
                    stack[top-1] = a+b; 
                    break;
                case '-':
                    stack[top-1] = a-b;
                    break;
                case '*':
                    stack[top-1] = a*b;
                    break;
            }
        }
    }
    
    printf("%d\n", stack[0]);
}