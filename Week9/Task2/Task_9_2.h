typedef void (*calcFuncPtr)(int, int, int, int, int*, int*);

void plus(int r1, int i1, int r2, int i2, int* r3, int* i3);

void minus(int r1, int i1, int r2, int i2, int* r3, int* i3);

void mult(int r1, int i1, int r2, int i2, int* r3, int* i3);

void calc(int r1, int i1, int r2, int i2, int* r3, int* i3, calcFuncPtr func);

