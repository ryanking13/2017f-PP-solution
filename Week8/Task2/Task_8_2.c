
int my_strlen(char *str){
	int cnt;
	for(cnt = 0; str[cnt] != '\0'; cnt++);
	return cnt;
}

void my_strrev(char *str1, char *str2){
	int len = my_strlen(str1);
	int i;
	for(i=0; i < len; i++){
		str2[i] = str1[len-1-i];
	}
	str2[len] = '\0';
}
