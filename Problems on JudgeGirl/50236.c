/* mergeString.h
void mergeString(char** P, char L[26], char* A);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "mergeString.h"
 
#define MAXN 200

int complete(char **P, char L[26], char *A, int idxs[MAXN]){
    for(int i = 0 ; P[i] != NULL ; i++){
        if(idxs[i] < strlen(P[i])){
            return 0;
        }
    }
    return 1;
}

void mergeString(char** P, char L[26], char* A){
    int idxs[MAXN] = {0};
    int A_idx = 0; 
    while(!complete(P, L, A, idxs)){
        char smallest = L[0];
        int smallest_idx = 26;
        int str_idx = 200; 
        for(int i = 0 ; P[i] != NULL ; i++){
            //printf("i %d\n", i);
            //printf("%s\n", P[i]);
            if(P[i][idxs[i]] != '\0'){
                int w = strchr(L, P[i][idxs[i]]) - L;
                //printf("w %d\n", w);
                //printf("pass\n");
                if(w < smallest_idx){
                    smallest = L[w];
                    smallest_idx = w;
                    str_idx = i;
                }
            }
        }
        //printf("smallest %c str_idx %d\n", smallest, str_idx);
        A[A_idx] = smallest;
        //printf("inserted %c\n", A[A_idx]);
        A_idx++;
        idxs[str_idx]++;
    }
}



int main(){
    int n;
    scanf("%d", &n);
    char* P[n + 1];
    char* freeP[n];
    int lengthA = 0;
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d", &m);
        P[i] = (char*)malloc((m + 1) * sizeof(char));
        scanf("%s", P[i]);
        // We may change the pointers in P in mergeString,
        // so we make a copy of P to free them in the last step.
        freeP[i] = P[i];
        lengthA += m;
    }
    P[n] = NULL;
 
    char L[26], buffer[30];
    scanf("%s", buffer);
    strncpy(L, buffer, 26);
 
    char* A = (char *)malloc((lengthA + 1) * sizeof(char));
    mergeString(P, L, A);
    A[lengthA] = '\0';
    printf("%s\n", A);
 
    // free the memory
    for(int i = 0; i < n; i++){
        free(freeP[i]);
    }
    free(A);
}