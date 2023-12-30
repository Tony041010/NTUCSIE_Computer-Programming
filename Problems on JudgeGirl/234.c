#include<stdio.h>
#include<math.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int d, e, f;

    if(d+e+f != a){

        d=1, e=1, f=c;
        for(int i = 1 ; i < f ; i++){
            if(f%i==0 && f/i >= e*i){
                e*=i, f/=i;
                break;
            }
        }

    }
    for(int i = 1 ; i<pow(c, 1.0/3) ; ){
        d = i;
        for(int j = i ; j < pow(c, 1/3) ; ){
                e = j;
        }
        for(int k = c ; k > 1 ; ){
            f = k;


        }
    }
    // d e   f
    // 1 1 223
    // 1 
    
}