#include<stdio.h>
#include<math.h>

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        
        // a(x1, y1) b(x2, y2) c(x3, y3)
        int x1, y1 , x2 , y2 , x3, y3;
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
        int ab_v = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        int bc_v = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        int ca_v = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        int B,M,S; //big medium small
        if(ab_v >= bc_v){
            if(ab_v <= ca_v){
                B = ca_v, M = ab_v, S = bc_v; 
            }
            else{
                if(bc_v >= ca_v){
                    B = ab_v, M = bc_v, S = ca_v;
                }
                else{
                    B = ab_v, M = ca_v, S = bc_v;
                }
            }
        }
        else{ 
            if(bc_v <= ca_v){
                B = ca_v, M = bc_v, S = ab_v; 
            }
            else{
                if(ab_v >= ca_v){
                    B = bc_v, M = ab_v, S = ca_v;
                }
                else{
                    B = bc_v, M = ca_v, S = ab_v;
                }
            }
        }

        //compare
        if(B == M || M == S){
            printf("isosceles\n");
        }
        else{
            if(M + S == B){
                printf("right\n");
            }
            else if(M + S > B){
                printf("acute\n");
            }
            else{
                printf("obtuse\n");
            }
        }

    }
}