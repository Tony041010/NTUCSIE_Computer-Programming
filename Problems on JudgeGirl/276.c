#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLEN 127

int main(){

    char word[MAXLEN+1];

    char Abbreviation[MAXLEN+1] = "";
    int Abb_idx = 0;
    while(scanf("%s", word) != EOF){
        
        int length = strlen(word);
        
        if(strcmp(word, "the") == 0 || strcmp(word, "of") == 0 || strcmp(word, "and") == 0 || strcmp(word, "at") == 0 
        ||strcmp(word, "the.") == 0 || strcmp(word, "of.") == 0 || strcmp(word, "and.") == 0 || strcmp(word, "at.") == 0){
            if(word[length-1] == '.'){
                printf("%s\n", Abbreviation);
                strcpy(Abbreviation, "");
            }
            continue;
        }

        char C[2] = "\0";
        C[0] = toupper(word[0]);
        strcat(Abbreviation, C);
        //printf("inserted\n");
        if(word[length-1] == '.'){
            printf("%s\n", Abbreviation);
            strcpy(Abbreviation, "");
        }

    }
    return 0;

}