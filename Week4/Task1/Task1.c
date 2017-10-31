#include <stdio.h>

int main()
{
	int alpha[26] = {};
	char cur;
	while (scanf("%c", &cur) != -1) {
		if (cur >= 'a')
			alpha[cur - 'a']++;
		else
			alpha[cur - 'A']++;
	}
	int i;
	for (i = 0; i < 26; i++) {
		if (alpha[i])
			printf("%c %d\n", 'a' + i, alpha[i]);
	}
}
