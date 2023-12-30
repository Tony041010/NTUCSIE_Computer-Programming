#include<stdio.h>
#include<stdbool.h>

int main(){

    int digit;
    int f1 = 0, f2 = 0, f3 = 0, s1 = 0, s2 = 0, s3 = 0; // positions of first and second 1 2 3 in sec_longest
    int lf1 = 0, lf2 = 0, lf3 = 0, ls1 = 0, ls2 = 0, ls3 = 0; // positions of first and second 1 2 3 in longest
    int la_f1 = 0, la_f2 = 0, la_f3 = 0; // positions of the lastest ones
    bool is_f1 = true, is_f2 = true, is_f3 = true; //first time apeear
    int numbers = 0;
    int longest_1 = 0, sec_longest_1 = -1, longest_2 = 1, sec_longest_2 = 0, longest_3 = 1, sec_longest_3 = 0;
    while(scanf("%d", &digit) != EOF){
        int distance = 0;
        switch(digit){
            case 1:
                if(is_f1){
                    f1 = numbers, lf1 = numbers, la_f1 = numbers;
                    //printf("%d %d %d\n", f1, lf1, la_f1);
                    is_f1 = false;
                    break;
                }
                distance = numbers - la_f1;
                //printf("%d", distance);
                if(distance == sec_longest_1){ // the lastest
                    //printf("A\n");
                    f1 = la_f1, s1 = numbers;
                }
                else if(distance == longest_1){ 
                    //printf("B\n");
                    lf1 = la_f1, ls1 = numbers;
                }
                else if(distance > sec_longest_1 && distance < longest_1){ //new sec_longest
                    //printf("C\n");
                    sec_longest_1 = distance;
                    f1 = la_f1, s1 = numbers;
                }
                else if(distance > longest_1){ // longest -> sec
                    //printf("D\n");
                    sec_longest_1 = longest_1;
                    longest_1 = distance;
                    f1 = lf1, s1 = ls1;
                    lf1 = la_f1 , ls1 = numbers;
                }
                la_f1 = numbers;
                break;
            case 2:
                if(is_f2){
                    f2 = numbers, lf2 = numbers, la_f2 = numbers;
                    //printf("%d %d %d\n", f1, lf1, la_f1);
                    is_f2 = false;
                    break;
                }
                distance = numbers - la_f2;
                //printf("%d", distance);
                if(distance == sec_longest_2){ // the lastest
                    //printf("A\n");
                    f2 = la_f2, s2 = numbers;
                }
                else if(distance == longest_2){ 
                    //printf("B\n");
                    lf2 = la_f2, ls2 = numbers;
                }
                else if(distance > sec_longest_2 && distance < longest_2){ //new sec_longest
                    //printf("C\n");
                    sec_longest_2 = distance;
                    f2 = la_f2, s2 = numbers;
                }
                else if(distance > longest_2){ // longest -> sec
                    //printf("D\n");
                    sec_longest_2 = longest_2;
                    longest_2 = distance;
                    f2 = lf2, s2 = ls2;
                    lf2 = la_f2 , ls2 = numbers;
                }
                la_f2 = numbers;
                break;
            case 3:
                if(is_f3){
                    f3 = numbers, lf3 = numbers, la_f3 = numbers;
                    //printf("%d %d %d\n", f1, lf1, la_f1);
                    is_f3 = false;
                    break;
                }
                distance = numbers - la_f3;
                //printf("%d", distance);
                if(distance == sec_longest_3){ // the lastest
                    //printf("A\n");
                    f3 = la_f3, s3 = numbers;
                }
                else if(distance == longest_3){ 
                    //printf("B\n");
                    lf3 = la_f3, ls3 = numbers;
                }
                else if(distance > sec_longest_3 && distance < longest_3){ //new sec_longest
                    //printf("C\n");
                    sec_longest_3 = distance;
                    f3 = la_f3, s3 = numbers;
                }
                else if(distance > longest_3){ // longest -> sec
                    //printf("D\n");
                    sec_longest_3 = longest_3;
                    longest_3 = distance;
                    f3 = lf3, s3 = ls3;
                    lf3 = la_f3 , ls3 = numbers;
                }
                la_f3 = numbers;
                break;
        }

        numbers++;

    }
    printf("%d %d %d\n", sec_longest_1, f1, s1);
    printf("%d %d %d\n", sec_longest_2, f2, s2);
    printf("%d %d %d\n", sec_longest_3, f3, s3);

}