#include<stdio.h>

int main(){
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

   //surface
    int in_a = a-2*e, in_b = b-2*e, in_c = c-2*e;
    int surface = 2*(a*b + b*c + c*a) + 8*(in_a*d + in_b*d + in_c*d);

    //volume
    int volume = a*b*c - 2*(in_a*in_b*d + in_b*in_c*d + in_c*in_a*d);

    printf("%d\n%d\n", surface, volume);


}