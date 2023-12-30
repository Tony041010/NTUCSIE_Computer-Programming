/* SpiralSnake.h
#ifndef SPIRALSNAKE_H_INCLUDED
#define SPIRALSNAKE_H_INCLUDED
void SpiralSnake(int N, int *snake, int *result);
#endif
*/

#include <stdio.h>
//#include "SpiralSnake.h"
#include <assert.h>
 
#define MAXLEN 1000
 
static int snake[MAXLEN*MAXLEN];
static int result[MAXLEN*MAXLEN];
 
void SpiralSnake(int N, int *snake, int *result){

    int centerRow = N/2;
    int centerCol = N/2;
    int currentIdx = centerRow*N + centerCol;
    int count = 0;
    result[currentIdx] = snake[count];

    for(int i = 1 ; i <= N-1 ; i++){
        if(i%2 == 0){ // go right and down
            for(int j = 0 ; j < i ; j++){ // go right
                currentIdx += 1;
                count += 1;
                result[currentIdx] = snake[count];
            }
            for(int j = 0 ; j < i ; j++){ // go down
                currentIdx += N;
                count += 1;
                result[currentIdx] = snake[count];
            }
            if(i == N-1){
                for(int j = 0 ; j < i ; j++){
                    currentIdx -= 1;
                    count += 1;
                    result[currentIdx] = snake[count];
                }
            }  
        }
        else{ // go left and up
            for(int j = 0 ; j < i ; j++){ // go left
                currentIdx -= 1;
                count += 1;
                result[currentIdx] = snake[count];
            }
            for(int j = 0 ; j < i ; j++){ // go up
                currentIdx -= N;
                count += 1;
                result[currentIdx] = snake[count];
            }
        }
    }
    return;
}



int main(){
    int N;
    while(scanf("%d", &N)!=EOF){
        for(int i=0; i<N*N; i++)
              assert(scanf("%d", &snake[i])==1);
        SpiralSnake(N, snake, result);
        for(int i=0; i<N*N; i++)
             printf("%d%c", result[i], " \n"[i==N*N-1]);
    }
    return 0;
}