#include<stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &(array[i]));
    }
    int M;
    scanf("%d", &M);
    int M_array[200000] = {0};
    for(int i = 0 ; i < n ; i++){
        M_array[(array[i]%M)]++;
    }
    for(int i = 0 ; i < M ; i++){
        printf("%d\n", M_array[i]);
    }
}