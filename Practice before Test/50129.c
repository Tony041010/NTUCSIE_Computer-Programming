/* loops.h
void loops(int N, int *A, int *B[], int ans[4]);
*/

#include <stdio.h>
#include <stdlib.h>
//#include "loops.h"
#define MAXN 1000000

int findLength(int idx, int *A, int *B[], int visited[], int *max, int *min){
    int *start = &A[idx];

    *max = A[idx];
    *min = A[idx];
    //printf("start %d M %d m %d\n", *start, *max, *min);
    visited[idx] = 1;
    int i = idx;
    int length = 1;
    while(*B[i] != *start){
        i = B[i] - A;
        length++;
        visited[i] = 1;
        if(*B[i] > *max){
            //printf("C M\n");
            *max = *B[i];
        }
        else if(*B[i] < *min){
            //printf("C m\n");
            *min = *B[i];
        }
    }
    return length;
}

void loops(int N, int *A, int *B[], int ans[4]){

    int visited[MAXN] = {0};

    int maxMax = 0;
    int minMin = N;
    int maxLength = 0;
    int minLength = N;
    int max = 0;
    int min = 0;
    for(int i = 0 ; i < N ; i++){
        if(!visited[i]){
            int length = findLength(i, A, B, visited, &max, &min);
            //printf("length %d\n", length);
            if(length > maxLength){
                maxLength = length;
                maxMax = max;
            }
            else if(length == maxLength && max > maxMax){
                maxMax = max;
            }

            if(length < minLength){
                minLength = length;
                minMin = min;
            }
            else if(length == minLength && min < minMin){
                minMin = min;
            }
            //printf("%d %d %d %d\n", maxLength, minLength, maxMax, minMin);
        }
    }
    ans[0] = maxLength;
    ans[1] = minLength;
    ans[2] = maxMax;
    ans[3] = minMin;

}

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