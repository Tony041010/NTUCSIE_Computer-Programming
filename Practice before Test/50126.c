/* merge.h
#include <stdio.h> 
void merge(int A[], int B[], int* a[], int* b[]);
*/


#include <stdio.h>
#include<stdbool.h>

void merge(int A[], int B[], int* a[], int* b[]){
    // your implementation here

    int **last = NULL;
    int index_A = 0;
    int index_B = 0;
    bool isAFinished = false;
    do{
        if(A[index_A] < B[index_B]){
            if(last == NULL){
                last = &a[index_A];
            }
            else{
                *last = &A[index_A];
                last = &a[index_A];
            }
            index_A++;
            isAFinished = true;
        }
        else{
            if(last == NULL){
                last = &b[index_B];
            }
            else{
                *last = &B[index_B];
                last = &b[index_B];
            }
            index_B++;
            isAFinished = false;
        }

    } while(*last != NULL);
    *last = (isAFinished) ? &B[index_B] : &A[index_A];

}

int main()
{
    int A[10], B[10];
    int *a[10], *b[10], *ans_a[10], *ans_b[10];
    int i, N, M;
 
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(i = 0; i < M; i++)
        scanf("%d", &B[i]);
    for(i = 0; i < N-1; i++)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for(i = 0; i < M-1; i++)
        b[i] = &B[i+1];
    b[M-1] = NULL;
 
    merge(A, B, a, b);
 
    ans_a[0] = &B[0];
    ans_a[1] = &A[2];
    ans_a[2] = &A[3];
    ans_a[3] = &B[1];
    ans_a[4] = &A[5];
    ans_a[5] = &B[2];
    ans_a[6] = &B[3];
 
    ans_b[0] = &A[1];
    ans_b[1] = &A[4];
    ans_b[2] = &A[6];
    ans_b[3] = NULL;
 
 
    for(i = 0; i < N; i++){
        if(a[i] != ans_a[i])
            printf("a[%d] is Wrong!\n", i);
    }
    for(i = 0; i < M; i++){
        if(b[i] != ans_b[i])
            printf("b[%d] is Wrong!\n", i);
    }
    printf("Finish!\n");
    return 0;
}