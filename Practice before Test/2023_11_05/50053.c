#include<stdio.h>
#include<string.h>

#define MAXM 100
#define MAXLEN 50

int search(char target[MAXLEN+1], char table[MAXM][MAXLEN+1], int N){
    for(int i = 0 ; i < N ; i++){
        if(strcmp(target, table[i]) == 0){
            return i;
        }
    }
    return -1;
}

int main(){

    int M;
    scanf("%d", &M);

    char author[MAXM][MAXLEN+1]; // for '\0'
    char book[MAXM][MAXLEN+1];

    char authorName[MAXM][MAXLEN+1];
    int numAuthor = 0;
    for(int i = 0 ; i < M ; i++){
        scanf("%s%s", author[i], book[i]);
        if(search(author[i], authorName, numAuthor) == -1){
            strcpy(authorName[numAuthor], author[i]);
            numAuthor++;
        }
    }

    int sold[MAXM] = {0};
    char copy[MAXLEN+1];
    int sale;
    for(int i = 0 ; i < M ; i++){
        scanf("%s%d", copy, &sale);
        sold[search(author[search(copy, book, M)], authorName, numAuthor)] += sale;
    }

    int max_sold = sold[0];
    int max_idx = 0;
    for(int i = 0 ; i < M ; i++){
        if((sold[i] > max_sold)||(sold[i] == max_sold && strcmp(authorName[i], authorName[max_idx]) < 0)){
            max_sold = sold[i];
            max_idx = i;
        }
    }

    printf("%s %d\n", authorName[max_idx], max_sold);


}