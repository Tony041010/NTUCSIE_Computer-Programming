#include<stdio.h>

#define MAXN 512
#define MAXK 128

int main(){

    int n, k;
    scanf("%d%d", &n, &k);

    int array[MAXN][MAXN];
    int filter[MAXK][MAXK];

    int outMat[MAXN-MAXK+1][MAXN-MAXK+1] = {{0}};

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &(array[i][j]));
        }
    }

    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < k ; j++){
            scanf("%d", &(filter[i][j]));
        }
    }

    for(int row = 0 ; row <= n-k ; row++){
        for(int col = 0 ; col <= n-k ; col++){
            int sum = 0;
            for(int dr = 0 ; dr < k ; dr++){
                for(int dc = 0 ; dc < k ; dc++){
                    sum += array[row+dr][col+dc] * filter[dr][dc];
                    //printf("%d ", array[row+dr][col+dc] * filter[dr][dc]);
                }
            }
            if(col == n-k){
                printf("%d\n", sum);
            }
            else{
                printf("%d ", sum);
            }
            //outMat[row][col] = sum;
            //printf("\n");
        }
    }

    // If use this, it'll be slower than the standard, so you'll fail in the final subtest.
    /*for(int i = 0 ; i < n-k+1 ; i++){
        for(int j = 0 ; j < n-k+1 ; j++){
            if(j == n-k){
                printf("%d\n", outMat[i][j]);
            }
            else{
                printf("%d ", outMat[i][j]);
            }
        }
    }*/

}