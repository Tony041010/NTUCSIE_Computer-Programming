/* The full code
#include<stdio.h>
#include<limits.h>
#include<assert.h>

int max(int array[5][5]){
    int MAX = INT_MIN;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(array[i][j] > MAX){
                MAX = array[i][j];
            }
        }
    }
    assert(MAX != INT_MIN);
    return MAX;

}

int main(){
    int array[5][5] = {{0}};
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            scanf("%d", &(array[i][j]));
        }
    }
    printf("%d\n", max(array));
    return 0;
}

*/

// The work required
//#include"max.h"
#include<limits.h>
#include<assert.h>

int max(int array[5][5]){
    int MAX = -10000000;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(array[i][j] > MAX){
                MAX = array[i][j];
            }
        }
    }
    return MAX;
}
