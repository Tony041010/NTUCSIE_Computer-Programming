#include<stdio.h>
#define arraysize 10

main(){

    int a[arraysize];

    printf("&a is %p\n", &a);
    printf("a is %p\n", a);
    printf("&(a[0]) is %p\n", &(a[0]));
    printf("a+3 is %p\n", a+3);
    printf("&(a[3]) is %p\n", &(a[3]));

}

/*
&a is 00000000005ffe70
a is 00000000005ffe70
&(a[0]) is 00000000005ffe70
a+3 is 00000000005ffe7c
&(a[3]) is 00000000005ffe7c
*/