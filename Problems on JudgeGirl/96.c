#include<stdio.h>
#include<assert.h>

# define pi 3.1415926

double max(double a, double b){
    return (a > b) ? a : b;
}

double min(double a, double b){
    return (a < b) ? a : b;
}

double area(double radius, double part){
    return radius*radius*pi*part;
}

int main(){

    double width, depth, rope;
    scanf("%lf%lf%lf", &width, &depth, &rope);

    assert(rope <= width+depth);

    double A;
    if(rope == width+depth){
        //printf("Hi0\n");
        A = area(rope, 3.0/4) + area(width, 1.0/4) + area(depth, 1.0/4);
    }
    else if(rope >= max(width, depth)){
        //printf("Hi1\n");
        A = area(rope, 3.0/4) + area(rope - max(width, depth), 1.0/4) + area(rope - min(width, depth), 1.0/4);
    }
    else if(rope < max(width, depth) && rope > min(width, depth)){
        //printf("Hi2\n");
        A = area(rope, 3.0/4) + area(rope - min(width, depth), 1.0/4);
    }
    else{
        //printf("Hi\n");
        A = area(rope, 3.0/4);
    }

    printf("%f", A);
}