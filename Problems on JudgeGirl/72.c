#include <stdio.h>
#include<limits.h>
//#include "fill_array.h"

// ptr[0] = &arr[0], ptr[n-1] = &arr[last]

void fill_array(int *ptr[], int n){
    for(int i = 0 ; i < n ; i++){
            *ptr[i] = i;
        }
    // sorting ptr;
    for(int N = n-2 ; N >= 2 ; N--){
        for(int i = 1 ; i < N ; i++){ // range : ptr[1] ~ ptr[n-2]
            int A = ptr[i] - ptr[0];
            int B = ptr[i+1] - ptr[0];
            //printf("A %d B %d\n", A, B);
            if(A > B){
                int *temp = ptr[i+1];
                ptr[i+1] = ptr[i];
                ptr[i] = temp;
            }
        }
    }

    /*for(int i = 0 ; i < n ; i++){
        printf("%d ", ptr[i] - ptr[0]);
    }
    printf("\n"); */

    for(int i = 0 ; i < n-1 ; i++){
        int L = ptr[i] - ptr[0];
        int R = ptr[i+1] - ptr[0];
        //printf("L %d R %d\n", L, R);
        for(int idx = L+1 ; idx < R ; idx++){
            *(ptr[0]+idx) = *ptr[i] + *ptr[i+1];
        }
    }

}

int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}