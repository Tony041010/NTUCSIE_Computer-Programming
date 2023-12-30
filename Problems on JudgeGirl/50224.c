#include<stdio.h>
int main(){

    int number;
    int max_digit_sum = 0;
    int value_of_max_digit_sum;
    while(scanf("%d", &number) != EOF){
        int digit_sum = 0;
        for(long long int i = 1 ; i <= number ; i*=10){
            digit_sum += (number/i)%10;
        }
        //printf("%d\n", digit_sum);
        if(digit_sum > max_digit_sum){
            max_digit_sum = digit_sum;
            value_of_max_digit_sum = number;
        }
        else if(digit_sum == max_digit_sum){
            for(long long int i = 10 ; i > 1 ; i*=10){
                if(number/i == 0 && value_of_max_digit_sum/i != 0){
                    value_of_max_digit_sum = number;
                    break;
                }
                else if(number/i == 0 && value_of_max_digit_sum/i == 0){
                    if(number > value_of_max_digit_sum){
                        value_of_max_digit_sum = number;
                    }
                    break;
                }
                else if(number/i != 0 && value_of_max_digit_sum/i == 0){
                    break;
                }
            }
        }
    }
    printf("%d\n", value_of_max_digit_sum);

}