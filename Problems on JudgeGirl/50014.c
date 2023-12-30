/* subset.h
int subset(int numbers[], int n, int K, int S);
*/

#include<stdio.h>
#include<stdbool.h>
//#include "subset.h"

/* K : sum. S : number of selection */
bool subset(int numbers[], int n, int K, int S){
    if(S > n){
        return false;
    }
    if(S == 0){
        return (K==0);
    }
    if(K < 0){
        return false;
    }

    return (subset(numbers, n-1, K, S) ||
            subset(numbers, n-1, K-numbers[n-1], S-1));

}

int main() {
    int n, K, S;
    while (scanf("%d %d %d", &n, &K, &S) == 3) {
        int A[128];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        printf("%d\n", subset(A, n, K, S));
    }
    return 0;
}