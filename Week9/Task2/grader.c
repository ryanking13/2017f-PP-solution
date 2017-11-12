#include <stdio.h>
#include "Task_9_2.h"

/*
typedef void (*calcFuncPtr)(int, int, int, int, int*, int*);

void plus(int r1, int i1, int r2, int i2, int* r3, int* i3){
    *r3 = r1 + r2;
    *i3 = i1 + i2;
}

void minus(int r1, int i1, int r2, int i2, int* r3, int* i3){
    *r3 = r1 - r2;
    *i3 = i1 - i2;
}

void mult(int r1, int i1, int r2, int i2, int* r3, int* i3){
    *r3 = r1 * r2 - i1 * i2;
    *i3 = r1 * i2 + r2 * i1;
}

void calc(int r1, int i1, int r2, int i2, int* r3, int* i3, calcFuncPtr func){
    func(r1, i1, r2, i2, r3, i3);
}

*/

int main(){
    calcFuncPtr f = NULL;
    int n1[2], n2[2], res[2];
    char op;

    scanf("%d %d %c %d %d", &n1[0], &n1[1], &op, &n2[0], &n2[1]);
    
    switch(op){
        case '+':
            f = plus;
            break;
        case '-':
            f = minus;
            break;
        case '*':
            f = mult;
            break;
    }

    calc(n1[0], n1[1], n2[0], n2[1], &res[0], &res[1], f);
    printf("%d %d\n", res[0], res[1]);
    return 0;    
}
