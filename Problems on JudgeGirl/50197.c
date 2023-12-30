#include<stdio.h>


int main(){

    int k;
    scanf("%d", &k);
    for(int i = 1 ; i <= 9 ; i++){
        for(int j = (i-k>0) ? i-k : 0 ; j <= ( (i+k > 9) ? 9 : i+k ); j++){
            for(int l = (j-k>0) ? j-k : 0 ; l <= ( (j+k > 9) ? 9 : j+k ); l++){
                for(int m = (l-k>0) ? l-k : 0 ; m <= ( (l+k > 9) ? 9 : l+k ); m++){
                    printf("%d%d%d%d\n", i, j, l, m);
                }
            }
        }
    }
}