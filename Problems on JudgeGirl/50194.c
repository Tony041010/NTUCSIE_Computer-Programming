#include<stdio.h>

int main(){

    int k, L;
    scanf("%d%d", &k, &L);

    int number;
    int digits_left = L;
    
    while(scanf("%d", &number) != EOF){
        if(number==0){
            break;
        } 
        
        int times = number % k;
        int digit_of_num=0;
        for(int i = number ; i > 0 ; i/=10){
            digit_of_num++;
        }
        //printf("%d\n", digit_of_num);
        
        int all_digits = times * digit_of_num;
        if(all_digits <= digits_left){ //non-exceeding
            for(int i = 0 ; i < times ; i++){
                printf("%d", number);
                digits_left -= digit_of_num;
            }
            if(digits_left==0){
                printf("\n");
                digits_left = L;
            }
        }
        else{//exceeding
            if(all_digits > L){
                continue;
            }
            else{
                digits_left = L;
                printf("\n");
                for(int i = 0 ; i < times ; i++){
                    printf("%d", number);
                    digits_left -= digit_of_num;
                }
                if(digits_left==0){
                    printf("\n");
                    digits_left = L;
                }
            }
        }

    }


}