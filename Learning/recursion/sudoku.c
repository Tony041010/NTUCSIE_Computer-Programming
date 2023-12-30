#include<stdio.h>
#include<stdbool.h>

/* placenumber */
#define SUBBLOCK 3
#define BLOCK 9
#define CELLS (BLOCK*BLOCK)

bool placeNumber(int n, int sudoku[BLOCK][BLOCK]){

    if(n == CELLS){
        for(int i = 0 ; i < BLOCK ; i++){
            for(int j = 0 ; j < BLOCK ; j++){
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
        return true;
    }

    int row = n / BLOCK;
    int col = n % BLOCK;
    if(sudoku[row][col] != 0){ // if the block already has a number
        return (placeNumber(n+1, sudoku));
    }

    for(int try = 1 ; try <= BLOCK ; try++){ // try to put 1 ~ 9 in that block
        bool conflict = false;
        for(int i = 0 ; i < BLOCK && !conflict ; i++){
            if((row != i && sudoku[i][col] == try) || (col != i && sudoku[row][i] == try)){
                conflict = true;
            }
        }
        if(!conflict){ // check if it's also valid in the subblock
            int subRow = row / SUBBLOCK;
            int subCol = col / SUBBLOCK;
            for(int i = 0 ; i < SUBBLOCK && !conflict ; i++){
                for(int j = 0 ; j < SUBBLOCK && !conflict ; j++){
                    if(sudoku[subRow * SUBBLOCK + i][subCol * SUBBLOCK + j] == try){
                        conflict = true;
                    }
                }
            }
            if(!conflict){
                sudoku[row][col] = try;
                if(placeNumber(n+1, sudoku)){
                    return true;
                }
            }
        }
    }
    sudoku[row][col] = 0;
    return false;
}

int main(){

    int sudoku[BLOCK][BLOCK];
    for(int i = 0 ; i < BLOCK ; i++){
        for(int j = 0 ; j < BLOCK ; j++){
            scanf("%d", &(sudoku[i][j]));
        }
    }
    placeNumber(0, sudoku);
    return 0;    
}