#include<stdio.h>

int main(){

    int N, M, times = 0;
    scanf("%d%d", &N, &M);
    for(int i = 1 ; i <= M ; i*=10){
        int n2 = N%10;
        int m2 = (i >= 10) ? ((M/i)%10)  : M%10;
        if(n2 == m2){
            int n1 = N/10;
            int m1 = ((M/(i*10))%10);
            if(n1 == m1){
                times++;
            }
        }
        
    }
    printf("%d\n", times);
}