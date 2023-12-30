/* loops.h
void loops(int N, int *A, int *B[], int ans[4]);
*/

int findloop(int N, int *A, int *B[], int index, int *max, int *min, int visited[]){

    // Because A[index] won't go through the loop. Therefore, when initializing, we let *max = *min = A[index]
    int start = A[index];
    *max = A[index];
    *min = A[index];
    int i = index;
    visited[index] = 1;
    int length = 1;

    while(*B[i] != start){
        i = B[i] - A;
        visited[i] = 1;
        if(A[i] > *max){
            *max = A[i];
        }
        if(A[i] < *min){
            *min = A[i];
        }
        length++;
    }

    return length;
}

void loops(int N, int *A, int *B[], int ans[4]){

    int visited[N];
    for(int i = 0 ; i < N ; i++){
        visited[i] = 0;
    }

    int max, min;
    int maxlength = 0;
    int minlength = N+1;
    int maxMax, minMin;

    for(int i = 0 ; i < N ; i++){

        if(visited[i] == 0){
            int length = findloop(N, A, B, i, &max, &min, visited);

            if(length > maxlength){
                maxlength = length;
                maxMax = max;
            }
            else if(length == maxlength && max > maxMax){
                maxMax = max;
            }

            if(length < minlength){
                minlength = length;
                minMin = min;
            }
            else if(length == minlength && min < minMin){
                minMin = min;
            } 
        }
    }

    ans[0] = maxlength;
    ans[1] = minlength;
    ans[2] = maxMax;
    ans[3] = minMin;
    
    return;
}


#include <stdio.h>
#include <stdlib.h>
//#include "loops.h"
#define MAXN 100
int main(){
    int N;
    int *A = (int *)malloc(sizeof(int) * MAXN);
    int **B = (int **)malloc(sizeof(int *) * MAXN);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", A + i);
    for(int i = 0, ptr; i < N; i++){
        scanf("%d", &ptr);
        B[i] = A + ptr;
    }
    int ans[4];
    loops(N, A, B, ans);
    for(int i = 0; i < 4; i++)
        printf("%d\n", ans[i]);
    return 0;
}