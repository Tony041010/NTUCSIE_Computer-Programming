/* card.h
void shuffle(int *deck[]);
void print(int *deck[]);
*/

#include <stdio.h>
//#include "card.h"

void shuffle(int *deck[]){

    int n = 0;
    for(int i = 0 ; i < 10000 ; i++){
        if(deck[i] == NULL){
            n = i;
            break;
        }
    }
    int firstceil = (n%2==0) ? n/2 : n/2+1;
    //printf("pass. n = %d\n", n);
    int *temp[n];
    for(int i = 0 ; i < n ; i+=2){
        temp[i] = deck[i/2];
        if(i+1 < n){
            temp[i+1] = deck[(firstceil+(i/2))];
        }
        //printf("%d %d\n", *temp[i], *temp[i+1]);
    }

    for(int i = 0 ; i < n ; i++){
        //printf("%d %d\n", *deck[i], *temp[i]);
        deck[i] = temp[i];
    }

}

void print(int *deck[]){

    for(int i = 0 ; i < 10000 ; i++){
        if(deck[0] == NULL){
            break;
        }
        if(deck[i+1] == NULL){
            printf("%d", *deck[i]);
            break;
        }
        else{
            printf("%d ", *deck[i]);
        }
    }
}



int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;
  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck); 
  return 0;
}