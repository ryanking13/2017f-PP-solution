#include <stdio.h>
#include "Task_10_1.h"
/*
struct complexNum {
	int real;
	int img;
};
typedef void (*calcFuncPtr)(struct complexNum, struct complexNum, int*, int*);

struct complexNum createComplexNum(int real, int img)
{
	struct complexNum newCom;
	newCom.real = real;
	newCom.img = img;
	return newCom;
}

void plus(struct complexNum input1, struct complexNum input2, int* output_real, int* output_img){
	*output_real = input1.real + input2.real;
	*output_img = input1.img + input2.img;
}
void minus(struct complexNum input1, struct complexNum input2, int* output_real, int* output_img){
	*output_real = input1.real - input2.real;
	*output_img = input1.img - input2.img;
}
void mult(struct complexNum input1, struct complexNum input2, int* output_real, int* output_img){
	*output_real = input1.real * input2.real - input1.img * input1.img;
	*output_img = input1.real * input2.img + input1.img * input2.real;
}


void calc(struct complexNum input1, struct complexNum input2, int* r3, int* i3, calcFuncPtr func){
	func(input1, input2, r3, i3);
}
*/
int main(){
    calcFuncPtr f = NULL;
    int n1[2], n2[2], res[2];
    char op;

    scanf("%d %d %c %d %d", &n1[0], &n1[1], &op, &n2[0], &n2[1]);

    struct complexNum newCom1;

    struct complexNum newCom2;

    newCom1 = createComplexNum(n1[0], n1[1]);
    newCom2 = createComplexNum(n2[0], n2[1]);
    
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

    calc(newCom1, newCom2, &res[0], &res[1], f);
    printf("%d %d\n", res[0], res[1]);
    return 0;    
}
