#include<stdio.h>

#define add 0
#define subtract 1
#define multi 2
#define division 3

// WATCH OUT THE NEGATIVES!

int main(){

    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

    //通分
    b = (a>0) ? a*c+b : a*c-b, f = (e>0) ? e*g+f : e*g-f;

    int h, i, j; // result : h+i/j

    switch(d){
    case add:
        i = b*g+f*c;
        j = c*g;
        break;
    case subtract:
        i = b*g - f*c;
        j = c*g;
        break;
    case multi:
        i = b*f;
        j = c*g;
        break;
    case division:        
        i = b*g;
        j = c*f;

        if(j < 0){
            i = -i;
            j = -j;
        }

        break;
    }
    int A = i, B = j;
    while(A%B != 0){
        int temp = B;
        B = A%B;
        A = temp;
    } // the gcc will be B after this loop
    B = (B < 0) ? -B : B;
    // reduction 
    i /= B;
    j /= B;

    h = i/j, i = (i > 0) ? i%j : (-i) %j;

    printf("%d\n%d\n%d\n", h, i, j);

}