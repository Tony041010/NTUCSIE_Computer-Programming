#include<stdio.h>
#include<string.h>

#define L 3
#define MAXLEN 10
#define DIR 6

int isIn(int row, int col, char *table[]){
    return (row >= 0 && row < L && col >= 0 && col < strlen(table[row]));
}

int main(){

    char *keyboard[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    char letter;
    int row, col;
    scanf("%c", &letter);
    printf("%c\n", letter);
    for(int i = 0 ; i < 3 ; i++){
        if(strchr(keyboard[i], letter) != NULL){
            row = i;
            col = strchr(keyboard[i], letter) - keyboard[i];
        }
    }
    int direction;
    int move[DIR][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};
    while(scanf("%d", &direction) != EOF){
        int newrow = row + move[direction][0];
        int newcol = col + move[direction][1];
        if(isIn(newrow, newcol, keyboard)){
            row = newrow;
            col = newcol;
            printf("%c\n", keyboard[row][col]);
        }
    }

}