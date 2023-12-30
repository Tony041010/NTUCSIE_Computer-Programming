#include<stdio.h>
#include<stdbool.h>

int main(){

    int timestamp;

    int min_time_diff = 86400, prev_seconds = 0;
    bool is_first = true;
    
    while(scanf("%d", &timestamp) != EOF){
        int seconds = 0;        
        for(int i = 1 ; i <= 10000 ; i*=100){
            switch(i){
            case 1:
                seconds += timestamp % (i*100);
                break;
            
            case 100:
                seconds += ((timestamp/i)%i)*60;
                break;
            case 10000:
                seconds += (timestamp/i)*3600;
                break;
            }
        }
        //printf("%d\n", seconds);

        if(is_first){
            prev_seconds = seconds;
            is_first = false;
        }
        else{
            int time_diff = (prev_seconds > seconds) ? prev_seconds-seconds : seconds-prev_seconds;
            min_time_diff = (time_diff < min_time_diff) ? time_diff : min_time_diff;
            prev_seconds = seconds;
            //printf("%d %d %d\n", time_diff, min_time_diff, prev_seconds);
        }

    }
    printf("%d\n", min_time_diff);

}