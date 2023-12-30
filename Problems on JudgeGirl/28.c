#include<stdio.h>
 
int sumSquare(int n){
    if(n == 1){
        return 1;
    }
    else{
        return (n*n + sumSquare(n-1));
    }
}
 
int main(){
 
    int n;
    scanf("%d", &n);
    printf("%d\n", sumSquare(n));
    return 0;
}