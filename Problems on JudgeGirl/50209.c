#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define R 3

bool in(int row, int col, int length[R]){
    return (row >= 0 && row < R && col >= 0 && col < length[row]);
}

int main(){

    char *keyboard[R] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    int length[R];
    for(int i = 0 ; i < R ; i++){
        length[i] = strlen(keyboard[i]);
    }

    char letter;
    scanf("%c", &letter);
    printf("%c\n", letter);

    int row, col;
    for(int i = 0 ; i < R ; i++){
        if(strchr(keyboard[i], letter) != NULL){
            row = i;
            col = strchr(keyboard[i], letter) - keyboard[i];
            break;
        }
    }
    int direction;
    int move[6][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};
    while(scanf("%d", &direction) != EOF){
        
        int newr = row + move[direction][0];
        int newc = col + move[direction][1];
        if(in(newr, newc, length)){
            row = newr;
            col = newc;
            printf("%c\n", keyboard[row][col]);
        }
       
    }

    return 0;
}