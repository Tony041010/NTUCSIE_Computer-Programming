#include<stdio.h>

int main(){

    int N, M;
    scanf("%d%d", &N, &M);
    int Sum[1000] = {0};
    int Max[1000] = {0};
    int Min[1000] = {0};
    for(int i = 0 ; i < 1000 ; i++){
        Min[i] = 10001;
    }

    int number;
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &number);
        Sum[(number%M)] += number;
        Max[(number%M)] = (Max[(number%M)] < number) ? number : Max[(number%M)];
        Min[(number%M)] = (Min[(number%M)] > number) ? number : Min[(number%M)];
    }

    for(int i = 0 ; i < M ; i++){
        printf("%d %d %d\n", Sum[i], Max[i], Min[i]);
    }

}