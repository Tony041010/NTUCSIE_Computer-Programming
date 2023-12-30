#include<stdio.h>
 
int main(){
 
    long long int A;
    while(scanf("%lld", &A) != EOF){
        int ones = 0;
        for(int i = 0 ; i < sizeof(A)*8 ; i++){
            if((A & 1) != 0){
                ones++;
            }
            A >>= 1;
        }
        printf("%d\n", ones);
    }
 
}