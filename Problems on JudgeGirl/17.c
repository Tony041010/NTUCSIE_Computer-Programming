#include<stdio.h>

int main(){

    int row, col;
    scanf("%d%d", &row, &col);
    int array[100][100] = {{0}};
    for(int r = 0 ; r < row ; r++){
        for(int c = 0 ; c < col ; c++){
            int temp;
            scanf("%d", &temp);
            array[r][c] = temp;
        }
    }
    int sum = 0;
    for(int c = 0 ; c < col ; c++){
        for(int r = 0 ; r < row ; r++){
            sum += array[r][c];
        }
        printf("%d\n", sum / row);
        sum = 0;
    }

}