#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void make_lower(char* p, char* s){
    int n = (int) strlen(s);
    for(int i=0;i<n;i++){
        if( s[i] >= 'A' && s[i] <= 'Z' ) p[i] = s[i] + 'a'-'A';
        else p[i] = s[i];
    }
    p[n] = '\0';
 
}
 
int is_delimiter(char c){
    if( c >= 'a' && c <= 'z' ) return 0;
    if( c >= 'A' && c <= 'Z' ) return 0;
    return 1;
}
char dict[100][100];
char word[1050], tmp[1050];
int M = 0;
 
int main(){
    FILE* fdict = (FILE*) fopen("./dict.txt","r");
    FILE* fin = (FILE*) fopen("./input.txt","r");
    FILE* fout = (FILE*) fopen("./output.txt","w");
    
    while( fscanf(fdict,"%s",dict[M++]) != EOF ){}
    char c;
    int p = 0;
    while( fscanf(fin,"%c",&c) != EOF ){
        if( is_delimiter(c) ){
            word[p] = '\0';
            int n = strlen(word);
             
            // check valid word
            if( n > 0 ){
 
                make_lower(tmp,word);
                int found = 0;
                for(int i=0;i<M;i++){
                    if( strcmp(tmp,dict[i]) == 0 ){
                        found = 1;
                        break;
                    }
                }
 
                if( found == 0 ){
                    fprintf(fout,"%s\n",word);
                }   
            }
            p = 0;  
        }
        else{
            word[p++] = c;
        }
    }
 
    fclose(fin);
    fclose(fdict);
    fclose(fout);
}