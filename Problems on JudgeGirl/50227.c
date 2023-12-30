#include<stdio.h>
#include<stdbool.h>

int main(){

    int one, two ,three, four;
    scanf("%d%d%d%d", &one, &two, &three, &four);
    int a, b, c, d;
    int A, B, C, D;
    bool found = false;
    for(a = one-6 ; a > one/4 ; a--){
        for(b = 3; b < a ; b++){
            for(c = 2; c < b ; c++){
                d = one-a-b-c;
                if(d >= c){
                    continue;
                }
                if(a+b+c+d == one && a*a+b*b+c*c+d*d == two && a*a*a+b*b*b+c*c*c+d*d*d == three && a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d == four){
                    found = true;
                    A=a, B=b, C=c, D=d;
                    break;    
                }
            }
            if(found){
                break;
            }
        }
        if(found){
            break;
        }
    }

    if(found){
        printf("%d\n%d\n%d\n%d", A, B, C, D);
    }
    else{
        printf("-1\n");
    }
}