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

