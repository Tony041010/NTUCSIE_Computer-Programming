#include<stdio.h>

int main(){

    int f[100] = {0};
    int g[100] = {0};
    int fg[200] = {0};
    int n, m;
    scanf("%d", &n);
    for(int i = n-1 ; i >= 0 ; i--){
        int temp;
        scanf("%d", &temp);
        f[i] = temp;
    }
    scanf("%d", &m);
    for(int i = m-1 ; i >= 0 ; i--){
        int temp;
        scanf("%d", &temp);
        g[i] = temp;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            fg[i+j] += f[i]*g[j];
        }
    }
    //n-1 + m-1 = n+m-2
    for(int i = n+m-2 ; i >=0 ; i--){
        if(i == n+m-2){
            printf("%d", fg[i]);
        }
        else{
            printf(" %d", fg[i]);
        }
    }

}