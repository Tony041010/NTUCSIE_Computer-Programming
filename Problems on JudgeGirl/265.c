#include<stdio.h>

int main(){

    int a, b;
    int x_max = -10001, x_min = 10001, y_max = -10001, y_min = 10001;
    
    while(scanf("%d%d", &a, &b) != EOF){
        x_max = (x_max < a) ? a : x_max;
        x_min = (x_min > a) ? a : x_min;
        y_max = (y_max < b) ? b : y_max;
        y_min = (y_min > b) ? b : y_min;

        //printf("%d %d %d %d\n", x_max, y_max, x_min, y_min);
    }
    
    //(x_max, y_max), (x_min, y_min)
    int area = (x_max - x_min)*(y_max - y_min);
    printf("%d", area);
}