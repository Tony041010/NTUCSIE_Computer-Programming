#include<stdio.h>
#include<stdbool.h>

int main(){

    int n;
    while(scanf("%d", &n) != EOF){
        int maxConsecutiveOnes = 0;
        int ones = 0;
        for(int i = 0 ; i < sizeof(int)*8 ; i++){
            if(n&1 != 0){
                ones++;
            }
            else{
                ones = 0;
            }
            n >>= 1;
            if(ones > maxConsecutiveOnes){
                maxConsecutiveOnes = ones;
            }
        }
        printf("%d\n", maxConsecutiveOnes);
    }

}