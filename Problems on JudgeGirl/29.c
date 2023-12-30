#include<stdio.h>
#include<stdbool.h>


int ways(int currentRow, int currentCol, int row, int col){
    if(currentRow == 1 && currentCol == 1){
        return 1;
    }
    else{
        if(currentRow == 1){
            return ways(currentRow, currentCol-1, row, col);
        }
        else if(currentCol == 1){
            return ways(currentRow-1, currentCol, row, col);
        }
        else{
            return ways(currentRow-1, currentCol, row, col) + ways(currentRow, currentCol-1, row, col);
        }
    }
}

int main(){

    int row, col;
    scanf("%d%d", &row, &col);
    printf("%d\n", ways(row, col, row, col));
    return 0;
}