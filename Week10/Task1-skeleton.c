#include <stdio.h>
struct complexNum {
	int real;
	int img;
}; 
typedef void (*calcFuncPtr)(struct complexNum, struct complexNum, int*, int*);

struct complexNum createComplexNum(int real, int img)
{
    // fill here
}

void plus (struct complexNum input1, struct complexNum input2, int* output_real, int* output_img){
    // fill here
}

void minus (struct complexNum input1, struct complexNum input2, int* output_real, int* output_img){
    // fill here
}

void mult (struct complexNum input1, struct complexNum input2, int* output_real, int* output_img){
    // fill here
}

void calc (struct complexNum input1, struct complexNum input2, int* r3, int* i3, calcFuncPtr func){
    // fill here
}

int main(){
    calcFuncPtr f = NULL;
    int r1, r2, r3, i1, i2, i3;
struct complexNum newCom1, newCom2;
    char op;

    scanf(“%d %d %c %d %d”, &r1, &i1, &op, &r2, &i2);
    switch(op){
        case ‘+’: f = plus; break;
case ‘-’: f = minus; break;
case ‘*’: f = mult; break;
    }

newCom1 = createComplexNum(r1, i1);
    newCom2 = createComplexNum(r2, i2); 
    calc(newCom1, newCom2, &r3, &i3, f);
    printf(“%d %d\n”, r3, i3);
    return 0;
}
