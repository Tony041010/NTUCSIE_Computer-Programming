#include <stdio.h>
#include <stdbool.h>
//#include "snake.h"

int snake(int *ptr, int *row, int *column){

    // if one row and all correct(done)
    // if multiple rows and all correct

    bool foundC = false;
    *row = 1;
    *column = 0;
    int R = 0;
    int C = 0;
    int currentRow = 0;
    int currentColumn = 0;
    for(int i = 1 ; *(ptr+i) != 0 ; i++){
        //printf("i %d\n", i);
        
        // find C
        if(!foundC){
            if(*(ptr+i) != i){
                R = 1;
                *column = C+1;
                foundC = true;
                //printf("found C %d\n", C);
            }
            else{
                C++;
                *column = C+1;
                continue;
            }
        }
        

        if(R % 2 == 0){
            //printf("non reverse\n");
            currentRow = i/(*column);
            currentColumn = i%(*column);
            //printf("cr %d cc %d\n", currentRow, currentColumn);
            if(currentRow%2 == 1){
                R++;
                continue;
            }
            if(*(ptr+i) != (currentRow)*(*column)+(currentColumn)){
                *row = currentRow;
                *column = currentColumn;
                return 0;
            }
        }  
        else{
            //printf("reverse\n");
            currentRow = i/(*column);
            currentColumn = (*column-1) - (i%(*column)); // column should be reversed
            //printf("cr %d cc %d\n", currentRow, currentColumn);
            if(currentRow%2 == 0){
                R++;
                continue;
            }
            if((*(ptr+i)) != ((currentRow)*(*column)+(currentColumn))){
                *row = currentRow;
                *column = currentColumn;
                return 0;
            }
        }       
    }
    //printf("%d\n", *column);
    *row = R+1;
    return 1;

}



int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}