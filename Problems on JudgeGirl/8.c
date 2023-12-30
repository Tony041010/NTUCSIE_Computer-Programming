#include<stdio.h>

int main(){

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    
    if(a+b <= c){
        printf("0");
    }
    else if(b+c <= a){
        printf("0");
    }
    else if(c+a <= b){
        printf("0");
    }
    else{
        printf("1");
    }
    
}