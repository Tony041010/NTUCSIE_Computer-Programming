#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLEN 100

int main(){

    char str[MAXLEN];
    char *VOWELS = "AEIOUaeiou";
    //char *V = VOWELS;
    int digits = 0;
    int letters = 0;
    int vowels = 0;
    int consonants = 0;
    scanf("%s", str);
    for(int i = 0 ; i < strlen(str) ; i++){
        //printf("%c\n", str[i]);
        if(isdigit(str[i])){
            digits++;
        }
        else if(isalpha(str[i])){
            letters++;
            if(strchr(V, str[i]) != NULL){
                vowels++;
            }
            else{
                consonants++;
            }
        }
    }
    printf("%d %d %d %d\n", digits, letters, vowels, consonants);
    return 0;

}