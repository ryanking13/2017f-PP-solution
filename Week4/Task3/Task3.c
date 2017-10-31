#include <stdio.h>
void main()
{
	int tmp[1000];
	int i;
	int count = 0;

	while (scanf("%d", &tmp[count++]) != EOF) {
		
	}
	for (i = count - 2; i >= 0; i--)
		printf("%d ", tmp[i]);

	return;
}