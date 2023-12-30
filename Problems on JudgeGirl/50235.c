#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAXC 3
#define MAXLEN 20

int f( char str[MAXLEN]){
    int sum = 0;
    for(int i = 0 ; i < MAXLEN && str[i] != '\0' ; i++){
        sum += str[i];
    }
    return sum % 1000;
}

int is_Valid(char str[MAXLEN]){

    if(isdigit(str[0])){
        return 0;
    }
    for(int i = 0 ; i < MAXLEN && str[i] != '\0' ; i++){
        if(!isalnum(str[i])){
            if(str[i] != '_'){
                return 0;
            }
        }
    }
    return 1;

}

int find(char str[MAXLEN], char strHash[1000][MAXC][MAXLEN], int HashValue){
    for(int c = 0 ; c < MAXC ; c++){
        if(strcmp(str, strHash[HashValue][c]) == 0){
            return c;
        }
    }
    return -1;
}

void insert(char str[MAXLEN], int Hash[1000][MAXC], char strHash[1000][MAXC][MAXLEN], int HashValue){
    for(int c = 0 ; c < MAXC ; c++){
        if(Hash[HashValue][c] == 0){
            Hash[HashValue][c] ++;
            strcpy(strHash[HashValue][c], str);
            printf("%s %d\n", str, Hash[HashValue][c]);
            break;
        }
    }
}

int main(){

    int Hash[1000][MAXC] = {{0}};
    char strHash[1000][MAXC][MAXLEN] = {{"\0"}};
    char str[MAXLEN];
    while(scanf("%s", str) != EOF){
        if(is_Valid(str)){
            int HashValue = f(str);
            int c = find(str, strHash, HashValue);
            if(c == -1){
                insert(str, Hash, strHash, HashValue);
            }
            else{
                Hash[HashValue][c]++;
                printf("%s %d\n", str, Hash[HashValue][c]);
            }
        }

    }


}