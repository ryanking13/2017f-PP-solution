#include<stdio.h>
#include "Task_7_1.h"

int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	
	swap(&a, &b);
	
	printf("%d %d\n", a, b);
}