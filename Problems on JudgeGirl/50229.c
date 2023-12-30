#include<stdio.h>

int main(){

    int k;
    int capacity[20000];
    int volume[20000];
    scanf("%d", &k);
    for(int i = 0 ; i < k ; i++){
        scanf("%d", &(capacity[i]));
    }
    for(int i = 0 ; i < k ; i++){
        scanf("%d", &(volume[i]));
    }

    int i, j;
    while(scanf("%d%d", &i, &j) != EOF){
        if(i == k){
            volume[j] = capacity[j];
        }
        else if(j == k){
            volume[i] = 0;
        }
        else{
            int out_max = volume[i];
            int in_max = capacity[j] - volume[j];
            if(in_max >= out_max){
                volume[j] += out_max;
                volume[i] = 0;
            }
            else{
                volume[j] += in_max;
                volume[i] -= in_max;
            }
        }
    }

    for(int i = 0 ; i < k ; i++){
        if(i == 0){
            printf("%d", volume[i]);
        }
        else{
            printf(" %d", volume[i]);
        }
    }

}