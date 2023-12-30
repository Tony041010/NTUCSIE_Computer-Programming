#include<stdio.h>
#include<stdbool.h>
int main(){

    int year, month, first_day;
    scanf("%d%d%d", &year, &month, &first_day);
    
    bool is_valid = true;
    if(month < 1 || month > 12){
        is_valid = false;
    }
    else if(first_day < 0 || first_day > 6){
        is_valid = false;
    }

    int days = 0;
    if(month != 2){
        if(month <= 7){
            days = (month%2 == 0) ? 30 : 31;
        }
        else{
            days = (month%2 == 0) ? 31 : 30;
        }
    }
    else{
        if(year % 400 == 0){
            days = 29;
        }
        else{
            if(year % 100 != 0){
                days = (year%4 == 0) ? 29 : 28;
            }
            else{
                days = 28;
            }
        } 
    }
    if(is_valid){
        //start printing the calender
        printf(" Su Mo Tu We Th Fr Sa\n");
        printf("=====================\n");
        int times = 0; // recording when to \n
        for(int i = 0 ; i < first_day ; i++){
            printf("   ");
            times++;
        }
        for(int i = 1 ; i <= days ; i++){
            printf("%3d" , i);
            times++;
            if(times%7 == 0 && i != days){
                printf("\n");
            }
            if(i == days){
                printf("\n");
            }
        } 
        printf("=====================\n"); 
    }
    else{
        printf("invalid\n");
    }

}