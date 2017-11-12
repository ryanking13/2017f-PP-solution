#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 1000
#define N 10000
void swap(char ** p, char** q)
{
	char *tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
void sort_words(char *w[], int n)
{
	int i, j;
	for(i = 0; i < n; ++i)
		for(j = i+1; j< n; ++j)
			if(strcmp(w[i],w[j]) > 0)
				swap(&w[i], &w[j]);
}
int main(void)
{
	char word[MAXWORD];
	char *w[N];
	int n;
	int i, j;
	
	char* net_word[N];
	int net_word_count[N] = {0,};
	int net_count = 0;

	for(i = 0; scanf("%s", word)==1; ++i)
	{
		w[i] = calloc(strlen(word) + 1, sizeof(char));
		//error_exit_calloc_faild();
		strcpy(w[i], word);
	}
	n = i;
	sort_words(w, n);
//	n = i;
	for( i = 0; i < n; i++)
	{
		if(net_count != 0 && strcmp(w[i], net_word[net_count - 1])==0)
				net_word_count[net_count - 1]++;
		else
		{
			net_count++;
			net_word[net_count - 1] = calloc(strlen(w[i]) + 1, sizeof(char));
			strcpy(net_word[net_count-1], w[i]);
			net_word_count[net_count - 1]++;
		}
			
	}
/*
	for(i = 0; i < net_count; i++)
	{
		printf("WORD CURRENT %s :  %d\n",net_word[i], net_word_count[i]);
	}
*/
	for(i = 0 ; i < net_count - 1; i++)
		for(j = i + 1; j < net_count ; j++)
		{
			if(net_word_count[i] < net_word_count[j])
			{
				int tmp;
				tmp = net_word_count[i];
				net_word_count[i] = net_word_count[j];
				net_word_count[j] = tmp;

				swap(&net_word[i], &net_word[j]);
			}
		}
	for(i = 0; i < net_count;i++)
	{
		printf("%s\n", net_word[i]);
	}
	
	return 0;
}
