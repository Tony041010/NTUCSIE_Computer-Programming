/* evaluate_f.h
#include<limits.h>
int evaluate_f(int *iptr[], int n, int *index);
*/

#include <stdio.h>
#include<limits.h>
//#include "evaluate_f.h"

int f(int x, int y){
    return (4*x - 6*y);
}

int evaluate_f(int *iptr[], int n, int *index){

    int max = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        int value = 4*(*iptr[i])-6*(*(iptr[i]+1));
        //printf(" %d %d %d\n", *iptr[i], *(iptr[i]+1), value);

        if(value > max){
            max = value;
            *index = i;
        }
    
    }
    return max;

}

int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}