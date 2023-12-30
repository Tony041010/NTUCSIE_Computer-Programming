/* constructTable.h
int ***constructTable(int A[], int B[]);
*/
#include <stdio.h>
//#include "constructTable.h"
 
#define MAXN 100
#define MAXM 5000

int **first[MAXN];
int *second[MAXN*MAXM];

int ***constructTable(int A[], int B[]){

    int ***ptr = first;
    int count_A = 0;
    int count_B = 0;
    int i, j;
    for(i = 0 ; A[i] != 0 ; i++){
        *(ptr+i) = &second[count_A];
        for(j = 0 ; j < A[i] ; j++){
            second[count_A + j] = &B[count_B];
            //printf("%d\n", B[count_B]);
            while(B[count_B] != 0){
                count_B++;
            }
            count_B++; // to skip 0
        }
        second[count_A+j] = NULL;
        count_A += A[i];
        count_A++; // to skip NULL
    }
    *(ptr+i) = NULL;

    return first;
}


int main(){
    int N, M;
    int A[100] = {}, B[500] = {};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
    return 0;
}