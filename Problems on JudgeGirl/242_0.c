#include<stdio.h>
#include<math.h>

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int x1, y1, r1, x2, y2, r2, x3, y3, r3;
        scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2, &x3, &y3, &r3);
        int count = 0;
        for(int x = x1-r1; x<=x1+r1 ; x++){
            for(int y = y1 ; (x-x1)*(x-x1) + (y-y1)*(y-y1) <= r1*r1 ; y++){
                if((x-x2)*(x-x2) + (y-y2)*(y-y2) > r2*r2 && (x-x3)*(x-x3) + (y-y3)*(y-y3) > r3*r3){
                    count++;
                }
                else if((x-x2)*(x-x2) + (y-y2)*(y-y2) <= r2*r2 && (x-x3)*(x-x3) + (y-y3)*(y-y3) <= r3*r3){
                    count++;
                }
            }
            for(int y = y1-1 ; (x-x1)*(x-x1) + (y-y1)*(y-y1) <= r1*r1 ; y--){ // beware!
                if((x-x2)*(x-x2) + (y-y2)*(y-y2) > r2*r2 && (x-x3)*(x-x3) + (y-y3)*(y-y3) > r3*r3){
                    count++;
                }
                else if((x-x2)*(x-x2) + (y-y2)*(y-y2) <= r2*r2 && (x-x3)*(x-x3) + (y-y3)*(y-y3) <= r3*r3){
                    count++;
                }
            }
        }
        for(int x = x2-r2; x<=x2+r2 ; x++){
            for(int y = y2 ; (x-x2)*(x-x2) + (y-y2)*(y-y2) <= r2*r2 ; y++){
                if((x-x3)*(x-x3) + (y-y3)*(y-y3) > r3*r3 && (x-x1)*(x-x1) + (y-y1)*(y-y1) > r1*r1){
                    count++;
                }
 
            }
            for(int y = y2-1 ; (x-x2)*(x-x2) + (y-y2)*(y-y2) <= r2*r2 ; y--){
                if((x-x3)*(x-x3) + (y-y3)*(y-y3) > r3*r3 && (x-x1)*(x-x1) + (y-y1)*(y-y1) > r1*r1){
                    count++;
                }
            }
        }
        for(int x = x3-r3; x<=x3+r3 ; x++){
            for(int y = y3 ; (x-x3)*(x-x3) + (y-y3)*(y-y3) <= r3*r3 ; y++){
                if((x-x1)*(x-x1) + (y-y1)*(y-y1) > r1*r1 && (x-x2)*(x-x2) + (y-y2)*(y-y2) > r2*r2){
                    count++;
                }  
            }
            for(int y = y3-1 ; (x-x3)*(x-x3) + (y-y3)*(y-y3) <= r3*r3 ; y--){
                if((x-x1)*(x-x1) + (y-y1)*(y-y1) > r1*r1 && (x-x2)*(x-x2) + (y-y2)*(y-y2) > r2*r2){
                    count++;
                } 
            }
        }
        printf("%d\n", count);    
    }
    
}