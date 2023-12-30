#include<stdio.h>

// want : n / k
// we input n digit by digit

main(){

    int k;
    scanf("%d", &k);

    int count = 0, prev = 0;
    int toPrint;
    int digit;
    while( scanf("%d", &digit) != EOF ){
        int value = prev * 10 + digit;
        toPrint = value / k;
        if ( !(count == 0 && toPrint == 0) ){
            printf("%d", toPrint);
        }
        prev = value % k;
        count++;
    }
    if(count == 1 && toPrint == 0){
        printf("0\n");
    }
}