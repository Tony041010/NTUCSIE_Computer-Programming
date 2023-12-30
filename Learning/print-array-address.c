#include<stdio.h>
#define arraysize 10

main(){

    int a[arraysize];
    printf("%ld\n", sizeof(a[0])); // %d : implemented for representing long integer values
    printf("%ld\n", sizeof(a));
    
    for(int i = 0 ; i < arraysize ; i++){
        printf("%p\n", &(a[i]));
    }

}
/*
4
40
00000000005ffe70
00000000005ffe74
00000000005ffe78
00000000005ffe7c
00000000005ffe80
00000000005ffe84
00000000005ffe88
00000000005ffe8c
00000000005ffe90
00000000005ffe94
*/