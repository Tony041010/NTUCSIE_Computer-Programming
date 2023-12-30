#include<stdio.h>
 
int Choose(int index, int set[], int k, int n){
    if(index == n && k == 0){
        return 1;
    }
    else if(index == n && k != 0){
        return 0;
    }
    else{
        return Choose(index+1, set, k-set[index], n) + Choose(index+1, set, k, n);
    }
}
 
int main(){
 
    int n;
    scanf("%d", &n);
    int set[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &(set[i]));
    }
    int k;
    while(scanf("%d", &k) != EOF){
        printf("%d\n", Choose(0, set, k, n));
    }
 
}