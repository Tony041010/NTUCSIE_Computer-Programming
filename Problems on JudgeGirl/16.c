#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int odd_array[1000] = {0};
    int even_array[1000] = {0};
    int odd_idx = 0, even_idx = 0;
    for(int i = 0 ; i < n ; i++){
        int temp;
        scanf("%d", &temp);
        if(temp % 2 == 0){
            even_array[even_idx] = temp;
            even_idx++;
        }
        else{
            odd_array[odd_idx] = temp;
            odd_idx++;
        }
    }

    for(int i = 0 ; i < odd_idx ; i++){
        if(i == odd_idx - 1){
            printf("%d\n", odd_array[i]);
        }
        else{
            printf("%d ", odd_array[i]);
        }
    }
    for(int i = 0 ; i < even_idx ; i++){
        if(i == even_idx - 1){
            printf("%d\n", even_array[i]);
        }
        else{
            printf("%d ", even_array[i]);
        }
    }
}