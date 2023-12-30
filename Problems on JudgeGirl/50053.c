#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAXM 100
#define MAXLEN 50

int find(char target[MAXLEN], char source[MAXM][MAXLEN], int M){
    for(int i = 0 ; i < M ; i++){
        if(strcmp(target, source[i]) == 0){
            return i;
        }
    }
    return -1;
}

int main(){

    int M;
    scanf("%d", &M);

    char Authors[MAXM][MAXLEN];
    char AuthorName[MAXM][MAXLEN] = {"\0"};
    char Books[MAXM][MAXLEN];
    int NumAuthor = 0;
    
    for(int i = 0 ; i < M ; i++){
        scanf("%s%s", Authors[i], Books[i]);
        if(find(Authors[i], AuthorName, NumAuthor) == -1){
            strcpy(AuthorName[NumAuthor], Authors[i]);
            NumAuthor++;
        }
    }
    //printf("pass 1\n");

    int Sold[MAXM] = {0};
    char book[MAXLEN];
    int sell;
    for(int i = 0 ; i < M ; i++){
        scanf("%s%d", book, &sell);
        Sold[find(Authors[find(book, Books, M)], AuthorName, NumAuthor)] += sell;
    }

    int max_sold = Sold[0];
    int max_idx = 0;
    for(int i = 1 ; i < NumAuthor ; i++){
        if(Sold[i] > max_sold){
            max_sold = Sold[i];
            max_idx = i;
        }
        else if(Sold[i] == max_sold && strcmp(AuthorName[i], AuthorName[max_idx]) < 0){
            max_idx = i;
        }
    }
    printf("%s %d\n", AuthorName[max_idx], max_sold);
}