#include<stdio.h>

void swap(int numbers[], int i, int j){
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
    return;
}

void sort(int numbers[], int start, int end){
    for(int i = end ; i >= start ; i--){ // sort the numbers first
        for(int j = start ; j < i ; j++){
            if(numbers[j] > numbers[j+1]){
                int temp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    return;
}

void copyArray(int dest[], int source[], int N){
    for(int i = 0 ; i < N ; i++){
        dest[i] = source[i];
    }
    return;
}

void printPermutations(int front, int N, int numbers[]){
 
    if(front == N){
        for(int i = 0 ; i < N ; i++){
            printf("%d ", numbers[i]);
        }
        printf("\n");
        return;
    }
    else{
        int tempArray[10];
        for(int i = front ; i < N ; i++){
            /*process : swap the head -> copyArray -> sort -> call recursion -> copyArray -> swap*/
            swap(numbers, front, i);
            copyArray(tempArray, numbers, N);
            sort(numbers, front+1, N-1);
            printPermutations(front+1, N, numbers);
            copyArray(numbers, tempArray, N);
            swap(numbers, front, i);
        }
        return;
    }
}
 
int main(){
 
    int N;
    scanf("%d", &N);
 
    int numbers[N];
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &(numbers[i]));
    }
    for(int i = N-1; i >= 0 ; i--){ // sort the numbers first
        for(int j = 0 ; j < i ; j++){
            if(numbers[j] > numbers[j+1]){
                int temp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    //printf("finish sorting\n");
    printPermutations(0, N, numbers);
    return 0;
}