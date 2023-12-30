#include<stdio.h>

int main(){

    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);

    int a =4*s - 0.5*f - 2*t;
    int b = -4*s + 0.5*f + 3*t;
    int c = s-t;

    printf("%d\n%d\n%d\n", a, b, c);

}