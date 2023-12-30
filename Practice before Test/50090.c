/* count.h
#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED
void count(int **p[]);
#endif
*/

#include <stdio.h>
//#include "count.h"
 
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512

int insert(int *ptr, int *ptrTable[], int object[], int frequency[], int currentCount){
    for(int i = 0 ; i < currentCount ; i++){
        if(ptr == ptrTable[i]){
            frequency[i]++;
            return currentCount;
        }
    }
    // not found
    ptrTable[currentCount] = ptr;
    frequency[currentCount] = 1;
    object[currentCount] = *ptr;
    return currentCount + 1;
}

void count(int **p[]){
    int ***firstlevel = p;
    int count = 0;
    int frequency[MAX_NUM_PTR] = {0};
    int object[MAX_NUM_PTR];
    int *thirdLevelPtrTable[MAX_NUM_PTR];

    while(*firstlevel != NULL){
        int *thirdLevel = **firstlevel;
        count = insert(thirdLevel, thirdLevelPtrTable, object, frequency, count);
        firstlevel++;
    }
    int min = 514;
    int idx = 0;
    int times = 0;
    while(times != count){
        for(int i = 0 ; i < count ; i++){
            if(frequency[i] < min){
                min = frequency[i];
                idx = i;
            }
            else if(frequency[i] == min && object[i] < object[idx]){
                idx = i;
            }
        }
        printf("%d %d\n", object[idx], min);
        frequency[idx] = 514;
        min = 514;
        times++;
    }
}



int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 6;
  intVar[2] = 2;
  intVar[3] = 9;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[3];
  ptrArray[4] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[3];
 
  count(ptrArray);
 
  return 0;
}