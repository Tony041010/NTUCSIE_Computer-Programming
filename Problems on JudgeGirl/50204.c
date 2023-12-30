#include<stdio.h>

#define MAXN 100
#define GREEN 0
#define BLUE 1

int main(){
    //printf("Hi\n");
    int n, m;
    scanf("%d%d", &n, &m);

    int cube[MAXN][MAXN][MAXN];
    int value = 0;
    for(int idx = 0 ; idx < n ; idx++){
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++, value++){
                cube[idx][row][col] = value;
            }
        }
    }

    for(int i = 0 ; i < m ; i++){

        int plate[MAXN][MAXN];
        int type, index;
        scanf("%d%d", &type, &index);

        switch(type){
        case GREEN:
            for(int row = 0 ; row < n ; row++){
                for(int col = 0 ; col < n ; col++){
                    plate[col][n-row-1] = cube[index][row][col];
                }
            }
            for(int row = 0 ; row < n ; row++){
                for(int col = 0 ; col < n ; col++){
                    cube[index][row][col] = plate[row][col];
                }
            }
            break;

        case BLUE:
            for(int row = 0 ; row < n ; row++){
                for(int col = 0 ; col < n ; col++){
                    plate[col][n-row-1] = cube[row][col][index];
                }
            }
            for(int row = 0 ; row < n ; row++){
                for(int col = 0 ; col < n ; col++){
                    cube[row][col][index] = plate[row][col];
                }
            }
            break;
        }

    }

    for(int i = 0 ; i < n ; i++){
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < n ; c++){
                if(c == n-1){
                    printf("%d\n", cube[i][r][c]);
                }
                else{
                    printf("%d ", cube[i][r][c]);
                }
            }
        }
    }
    return 0;
}