#include<stdio.h>

int main(){

    int n, count_0 = 0, count_1 = 0, count_2 = 0;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int In;
        scanf("%d", &In);
        if(In % 3 == 0){
            count_0++;
        }
        else if(In % 3 == 1){
            count_1++;
        }
        else{
            count_2++;
        }
    }
    printf("%d %d %d\n", count_0, count_1, count_2);
}