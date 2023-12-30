#include<stdio.h>

int main(){

    int SPN1, SPN2, SPN3; //special prize numbers
    int FPN1, FPN2, FPN3; //first prize numbers
    scanf("%d%d%d%d%d%d", &SPN1, &SPN2, &SPN3, &FPN1, &FPN2, &FPN3);
    int lottery;
    long long int dollars = 0;
    while(scanf("%d", &lottery) != EOF){
        if(lottery == SPN1 || lottery == SPN2 || lottery == SPN3){
            dollars += 2000000;
        }
        else if(lottery == FPN1 || lottery == FPN2 || lottery == FPN3){
            dollars += 200000;
        }
        else{
            int max_digits = 7;
            for(int i = 10000000 ; i >= 1000 ; i /= 10){
                if((lottery % i) == (FPN1 % i) || (lottery % i) == (FPN2 % i) || (lottery % i) == (FPN3 % i)){
                    break;
                }
                else{
                    max_digits --; 
                }
            }
            //printf("%d\n", max_digits);
            switch(max_digits){
            case 7:
                dollars += 40000;
                break;
            case 6:
                dollars += 10000;
                break;
            case 5:
                dollars += 4000;
                break;
            case 4:
                dollars += 1000;
                break;
            case 3:
                dollars += 200;
                break;
            default:
                dollars += 0;
                break;
            }
        }
        
    }
    printf("%lld\n", dollars);
}