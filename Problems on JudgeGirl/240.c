#include<stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

        // ordering(x1, y1) ~ (x4, y4)
        int temp_x, temp_y;
        long long int Cross1 = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
        if(Cross1 < 0){
            temp_x = x2, temp_y = y2;
            x2=x3, y2=y3, x3 = temp_x, y3 = temp_y;
        }
        long long int Cross2 = (x3-x2)*(y4-y2) - (y3-y2)*(x4-x2);
        if(Cross2 < 0){
            temp_x = x3, temp_y = y3;
            x3=x4, y3=y4, x4 = temp_x, y4 = temp_y;
        }
        long long int Cross3 = (x4-x3)*(y1-y3) - (y4-y3)*(x1-x3);
        if(Cross3 < 0){
            temp_x = x4, temp_y = y4;
            x4=x1, y4=y1, x1 = temp_x, y1 = temp_y;
        }
        long long int Cross4 = (x1-x4)*(y2-y4) - (y1-y4)*(x2-x4);
        if(Cross4 < 0){
            temp_x = x1, temp_y = y1;
            x1=x2, y1=y2, x4 = temp_x, y4 = temp_y;
        }
        //printf("%d %d\n%d %d\n%d %d\n%d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
        // S:Square
        long long int L12S = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        long long int L23S = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        long long int L34S = (x4-x3)*(x4-x3) + (y4-y3)*(y4-y3);
        long long int L41S = (x1-x4)*(x1-x4) + (y1-y4)*(y1-y4);
        if(L12S == L23S && L23S == L34S && L34S == L41S && L41S == L12S){
            long long int CS = (x3-x1)* (x3-x1) + (y3-y1)*(y3-y1);
            if(L12S + L23S == CS){
                printf("square\n");
            }
            else{
                printf("diamond\n");
            }
        }
        else{
            long long int CS = (x3-x1)* (x3-x1) + (y3-y1)*(y3-y1);
            if(L12S + L23S == CS && L12S == L34S && L23S == L41S){
                printf("rectangle\n");
            }
            else{
                printf("other\n");
            }
        }

    }

}