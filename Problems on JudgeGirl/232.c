#include<stdio.h>
#include<stdbool.h>
int main(){

    int year, origin, n;
    scanf("%d%d", &year, &origin);
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int month, day;
        bool is_leap_year = false;

        if(year % 400 == 0){
            is_leap_year = true;
        }
        else{
            if(year % 100 != 0){
                if(year%4 == 0){
                    is_leap_year = true;
               }
            }
        }

        scanf("%d%d", &month, &day);
        if(month < 1 || month > 12){
            printf("-1\n");
            continue;
        }
        if(month <= 7){ // month 1~7 odd 31 even 28 or 30
            if(month % 2 == 0){
                if(month == 2){
                    if(is_leap_year){
                        if(day > 29 || day < 1){
                            printf("-2\n");
                            continue;
                        }
                    }
                    else{
                        if(day > 28 || day < 1){
                            printf("-2\n");
                            continue;
                        }
                    }
                    
                }
                else{
                    if(day > 30 || day < 1){
                        printf("-2\n");
                        continue;
                    }
                }
            }
            else{
                if(day > 31 || day < 1){
                    printf("-2\n");
                    continue;
                }
            }
        }
        else{ //month 8~12 odd 30 even 31
            if(month % 2 == 0){
                if(day > 31 || day < 1){
                    printf("-2\n");
                    continue;
                }
            }
            else{
                if(day > 30 || day < 1){
                    printf("-2\n");
                    continue;
                }
            }
        }

        //start counting
        int days = 0;
        for(int m = 1 ; m <= month ; m++){
            if(m != month){
                if(m <= 7){
                    if(m == 2){
                        days += (is_leap_year) ? 29 : 28;
                    }
                    else{
                        days += (m%2 == 0) ? 30 : 31;
                    }
                }
                else{
                    days += (m%2 == 0) ? 31 : 30;
                }
            }
            else{
                days += day;
                int Ans = (days+(origin-1))%7;
                printf("%d\n", Ans);
            }
        }


    }


}