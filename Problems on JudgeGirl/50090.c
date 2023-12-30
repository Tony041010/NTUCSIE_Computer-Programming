/* count.h
#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED
void count(int **p[]);
#endif
*/

#include <stdio.h>
//#include "count.h"

int visited(int *ptr, int *address[512]){
  for(int i = 0 ; i < 512 ; i++){
    if(address[i] == ptr){
      return 1;
    }
  }
  return 0;
}

void insert(int *ptr, int *address[512]){
  for(int i = 0 ; i < 512 ; i++){
    if(address[i] == NULL){
      address[i] = ptr;
      //printf("%d %d\n", i, *ptr);
      break;
    }
  }
  return;
}

void count(int **p[]){

    int numbers = 0;
    int *address[512];
    for(int i = 0 ; i < 512 ; i++){
      address[i] = NULL;
    }
    for(int i = 0 ; p[i] != NULL ; i++){
      if(!visited(*p[i], address)){
        insert(*p[i], address);
        numbers++;
      }
      //printf("%d\n", **p[i]);
    }

    //printf("numbers %d\n", numbers);
    int visitTimes[512] = {0};
    for(int i = 0 ; i < numbers ; i++){
      for(int j = 0 ; p[j] != NULL ; j++){
        if(*p[j] == address[i]){
          visitTimes[i]++;
        }
      }
    }
    int times = 0;
    while(times != numbers){
      int min = 513;
      int idx = 0;
      for(int i = 0 ; i < numbers ; i++){
        if(visitTimes[i] < min){
          min = visitTimes[i];
          idx = i;
        }
        else if(visitTimes[i] == min && *address[i] < *address[idx]){
          min = visitTimes[i];
          idx = i;
        }
      }
      printf("%d %d\n", *address[idx], min);
      visitTimes[idx] = 514;
      times++;
    }
    

}


#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
 
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 7;
  intVar[2] = 6;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[2];
  ptrArray[4] = &intPtr[3];
  ptrArray[5] = &intPtr[4];
  ptrArray[6] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[2];
  intPtr[4] = &intVar[1];
 
  count(ptrArray);
 
  return 0;
}