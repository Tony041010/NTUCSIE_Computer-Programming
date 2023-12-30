/* max.h
#include<limits.h>
int max(int *iptr[], int n);
*/

#include<stdio.h>
#include<limits.h>

int max(int *iptr[], int n){

    int M = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(*(iptr[i]) > M){
            M = *(iptr[i]);
        }
    }

    return M;
}

int main(){
    int n, i;
    int array[100];
    int *iptr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(array[(i + 3) % n]));
        iptr[i] = &(array[(i + 3) % n]);
    }
    printf("%d\n", max(iptr, n));
    return 0;

}