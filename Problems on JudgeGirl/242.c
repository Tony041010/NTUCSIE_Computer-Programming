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
            int y = y1;
            long long S_1 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
            for( ; S_1 <= r1*r1 ; y++){
                long long int S_2 = (x-x2)*(x-x2) + (y-y2)*(y-y2), S_3 = (x-x3)*(x-x3) + (y-y3)*(y-y3);
                if(S_2 > r2*r2 && S_3 > r3*r3){
                    count++;
                }
                else if(S_2 <= r2*r2 && S_3 <= r3*r3){
                    count++;
                }
                S_1 = (x-x1)*(x-x1) + (y+1-y1)*(y+1-y1);
            }
            for(int y = y1-1 ; S_1 <= r1*r1 ; y--){ // beware!
                long long int S_2 = (x-x2)*(x-x2) + (y-y2)*(y-y2), S_3 = (x-x3)*(x-x3) + (y-y3)*(y-y3);
                if(S_2 > r2*r2 && S_3 > r3*r3){
                    count++;
                }
                else if(S_2 <= r2*r2 && S_3 <= r3*r3){
                    count++;
                }
                S_1 = (x-x1)*(x-x1) + (y-1-y1)*(y-1-y1);
            }
        }

        for(int x = x2-r2; x<=x2+r2 ; x++){
            int y = y2;
            long long S_2 = (x-x2)*(x-x2) + (y-y2)*(y-y2);
            for(; S_2 <= r2*r2 ; y++){
                long long int S_3 = (x-x3)*(x-x3) + (y-y3)*(y-y3), S_1 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
                if(S_3 > r3*r3 && S_1 > r1*r1){
                    count++;
                } 
                S_2 = (x-x2)*(x-x2) + (y+1-y2)*(y+1-y2);
            }
            for(y = y2-1 ; S_2 <= r2*r2 ; y--){
                long long int S_3 = (x-x3)*(x-x3) + (y-y3)*(y-y3), S_1 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
                if(S_3 > r3*r3 && S_1 > r1*r1){
                    count++;
                }
                S_2 = (x-x2)*(x-x2) + (y-1-y2)*(y-1-y2);
            }
        }

        for(int x = x3-r3; x<=x3+r3 ; x++){
            int y = y3;
            long long int S_3 = (x-x3)*(x-x3) + (y-y3)*(y-y3);
            for(y = y3 ; S_3 <= r3*r3 ; y++){
                if((x-x1)*(x-x1) + (y-y1)*(y-y1) > r1*r1 && (x-x2)*(x-x2) + (y-y2)*(y-y2) > r2*r2){
                    count++;
                }  
                S_3 = (x-x3)*(x-x3) + (y+1-y3)*(y+1-y3);
            }
            for(y = y3-1 ; S_3 <= r3*r3 ; y--){
                if((x-x1)*(x-x1) + (y-y1)*(y-y1) > r1*r1 && (x-x2)*(x-x2) + (y-y2)*(y-y2) > r2*r2){
                    count++;
                } 
                S_3 = (x-x3)*(x-x3) + (y-1-y3)*(y-1-y3);
            }
        }
        printf("%d\n", count);    
    }
    
}