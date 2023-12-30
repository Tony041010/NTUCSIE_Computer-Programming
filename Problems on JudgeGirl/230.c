#include<stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int maxValue(int idx, int n, int W, int weight[], int value[]){
    if(idx >= n){
        return 0;
    }
    else if(weight[idx] > W){
        return maxValue(idx+1, n, W, weight, value);
    }
    else{
        return (max(maxValue(idx+1, n, W-weight[idx], weight, value) + value[idx], 
                    maxValue(idx+1, n, W, weight, value))); // take item[i] or not
    }
}

int main(){

    int n, W;
    scanf("%d%d", &n, &W);
    
    int weight[n];
    int value[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d", &(weight[i]), &(value[i]));
    }

    printf("%d\n", maxValue(0, n, W, weight, value));
}