/* chasing.h
void chasing(int **A[], int a, int *B[], int b, int C[], int c);
*/

#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//#include "chasing.h"

int isDigit(char *word){
    for(int i = 0 ; i < strlen(word) ; i++){
        if(!isdigit(word[i])){
            return 0;
        }
    }
    return 1;
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    
    for(int i = 0 ; i < a ; i++){
        A[i] = NULL;
    }
    for(int i = 0 ; i < b ; i++){
        B[i] = NULL;
    }
    char line[100];
    while(fgets(line, 100, stdin) != NULL){
        char *first = strtok(line, " \t\n");
        if(first == NULL){
           // printf("failed 1\n");
            printf("0\n");
            continue;
        }
        char *index1ptr = strtok(NULL, " \t\n");
        if(index1ptr == NULL){
            //printf("fail 2\n");
            printf("0\n");
            continue;
        }

        int index1;
        if(isDigit(index1ptr)){
            index1 = atoi(index1ptr);
        }
        else{
            //printf("fail 3\n");
            printf("0\n");
            continue;
        }

        char *second = strtok(NULL, " \t\n");
        if(second == NULL){
           //printf("fail 4\n");
            printf("0\n");
            continue;
        }
        char *index2ptr = strtok(NULL, " \t\n");
        if(index2ptr == NULL){
            //printf("fail 5\n");
            printf("0\n");
            continue;
        }

        int index2;
        if(isDigit(index2ptr)){
            index2 = atoi(index2ptr);
        }
        else{
            //printf("fail 6\n");
            printf("0\n");
            continue;
        }

        if(strtok(NULL, " \t\n") != NULL){ // if the command isn't just AnBm but longer 
           //printf("fail 7\n");
            printf("0\n");
            continue;
        }

        
        int correct = 1;
        if(strcmp(first, "A") == 0){
            if(strcmp(second, "B") != 0 || index1 < 0 || index1 >= a || index2 < 0 || index2 >= b){
                correct = 0;
            }
            else{
                A[index1] = &B[index2];
            }
        }
        else if(strcmp(first, "B") == 0){
            if(strcmp(second, "C") != 0 || index1 < 0 || index1 >= b || index2 < 0 || index2 >= c){
                correct = 0;
            }
            else{
                B[index1] = &C[index2];
            }
        }
        else{
            correct = 0;
        }
        //printf("Done(temply)\n");

        if(correct){
            printf("1\n");
        }
        else{
            printf("0\n");
        }

    }

}

int main() {
        int a = 5, b = 4, c = 3;
        int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[5] = {} ,*ansB[4] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);
 
        /*Check B*/
        for (int i = 0; i < b; i++)
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        return 0;
}