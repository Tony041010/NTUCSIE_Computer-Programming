#include<stdio.h>

int main(){

    // the i-th power of n
    int n, i;
    scanf("%d%d", &n, &i);
    int Ans = 1;
    for(int j = 0 ; j < i ; j++){
        Ans *= n;
    }
    printf("%d\n", Ans);
}