struct complexNum {
	int real;
	int img;
};
typedef void (*calcFuncPtr)(struct complexNum, struct complexNum, int*, int*);

struct complexNum createComplexNum(int real, int img);

void plus(struct complexNum input1, struct complexNum input2, int* output_real, int* output_img);
void minus(struct complexNum input1, struct complexNum input2, int* output_real, int* output_img);
void mult(struct complexNum input1, struct complexNum input2, int* output_real, int* output_img);


void calc(struct complexNum input1, struct complexNum input2, int* r3, int* i3, calcFuncPtr func);