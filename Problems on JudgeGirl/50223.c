#include<stdio.h>

int main(){

    int w, a, b, c, d, e;
    scanf("%d%d%d%d%d%d", &w, &a, &b, &c, &d, &e);
    long long int min_distance_S;
    if(b != 0){
        min_distance_S = w*w + (a + 2*d + b + 2*e + c + 2)*(a + 2*d + b + 2*e + c + 2 );
    }
    else{
        int det_walls = (e-d > 0) ? e-d : d-e;
        min_distance_S = w*w + (a + d + 1 + det_walls + 1 + e + c)*(a + d + 1 + det_walls + 1 + e + c);
    }
    printf("%lld\n", min_distance_S);
}