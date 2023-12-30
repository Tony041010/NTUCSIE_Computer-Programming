#include<stdio.h>

int main(){

    int a, b, c, d, e, f, g, h;
    scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
    
    //vectors
    int x1 = a, y1 = b, x2 = c, y2 = d, x3 = e, y3 = f, x4 = g, y4 = h;


    // order : 12 23 34 41
    int z1 = x1*y2 - y1*x2;
    int z2 = x2*y3 - y2*x3;
    int z3 = x3*y4 - y3*x4;
    int z4 = x4*y1 - y4*x1;

    if(z1 > 0 && z2 > 0 && z3 > 0  && z4 > 0){
        printf("1");
    }
    else if(z1 < 0 && z2 < 0 && z3 < 0  && z4 < 0){
        printf("1");
    }
    else{
        printf("0");
    }

}