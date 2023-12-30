#include<stdio.h>

int main(){

    int A, B;
    scanf("%d%d", &A, &B);
    int count_A = 0, count_B = 0;
    for(int i = 1 ; i <= 1000 ; i*=10){
        int a = (i >= 10) ? ((A/i)%10)  : A%10;
        for(int j = 1 ; j <= 1000 ; j*=10){
            int b = (j >= 10) ? ((B/j)%10) : B%10;
            if(a == b){
                if(i == j){
                    count_A ++;
                }
                else{
                    count_B++;
                }
            }
        }
    }
    printf("%dA%dB\n", count_A, count_B);
}