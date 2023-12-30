/* costructTable.h
int ***constructTable(int A[], int B[]);
*/

#include <stdio.h>
//#include "constructTable.h"

#define MAXN 100
#define MAXSECOND 100

int **first[MAXN];
int *second[MAXSECOND*MAXN]; 

int ***constructTable(int A[], int B[]){

    int ***firstPtr = first;
    int **secondPtr = second;
    int *BPtr = B;

    // key point : after firstPtr or secondPtr points to a target, we do a ++ immediately to switch to the next one.
    for(int i = 0 ; A[i] != 0 ; i++){
        *firstPtr = secondPtr;
        firstPtr++; //important and very useful
        for(int j = 0 ; j < A[i] ; j++){
            *secondPtr = BPtr;
            secondPtr++; //important and very useful
            while(*BPtr != 0){
                BPtr++;
            }
            BPtr++; // to skip 0
        }
        *secondPtr = NULL;
        secondPtr++; //important and very useful.
    }
    *firstPtr = NULL;
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