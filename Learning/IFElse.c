#include<stdio.h>

main(){

    int A, abs_A;
    scanf("%d", &A);

    // case 1 : normal if-else structure
    if(A >= 0){
        abs_A = A;        
    }
    else{
        abs_A = -A;
    }


    //case 2 : shorten structure (con) ? (state1) : (state2)
    abs_A = (A>0) ? A : -A;
    printf("%d", abs_A); 
}