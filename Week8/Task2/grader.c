#include<stdio.h>
#include "Task_8_2.h"

int main(){
	char s[1000];
	char s_rev[1000];
	int i;
	
	for(i=0; i < 1000; i++){
		s_rev[i] = 'a';
	}
	scanf("%s", s);
	
	int len = my_strlen(s);
	my_strrev(s, s_rev);
	
	printf("%d\n%s", len, s_rev);
}
