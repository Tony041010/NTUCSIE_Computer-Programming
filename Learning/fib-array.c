#include<stdio.h>
#include<assert.h>
#define fibarraysize 100


main(){

    int n;
    scanf("%d", &n);
    assert( n >= 2 && n < fibarraysize );

    int fib[fibarraysize];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2 ; i < n ; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i = 0 ; i < n ; i++){
        printf("%d\n", fib[i]);
    }

}