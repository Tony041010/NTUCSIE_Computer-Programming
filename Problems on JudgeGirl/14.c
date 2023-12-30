#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int array[1000] = {0};
    for(int i = 0 ; i < n ; i++){
        int temp;
        scanf("%d", &temp);
        array[i] = temp;
    }

    for(int i = n-1 ; i >= 0 ; i--){
        if(i == 0){
            printf("%d\n", array[i]);
        }
        else{
            printf("%d ", array[i]);
        }
    }
}