#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h> // for abs

#define QUEENS 8

void placeQueen(int i, int queensPos[QUEENS]){

    if(i == QUEENS){
        for(int k = 0 ; k < QUEENS ; k++){
            printf("%d ", queensPos[k]);
        }
        printf("\n");
        return;
    }

    for(int k = 0 ; k < QUEENS ; k++){ // try 8 different rows
        bool conflict = false;
        for(int j = 0 ; j < i && !conflict ; j++){
            if(queensPos[j] == k || abs(k - queensPos[j]) == (i-j)){ 
                // if the k-th row is used or is on the cross lines of the j-th queen
                conflict = true;
            }
        }
        if(!conflict){
            queensPos[i] = k;
            placeQueen(i+1, queensPos);
        }
    }
}

int main(){
    int queensPos[QUEENS];
    placeQueen(0, queensPos);
    return 0;
}