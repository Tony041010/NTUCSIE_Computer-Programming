#include<stdio.h>
#include<stdbool.h>
#define MAXN 8

typedef struct
{
    int number;
    int size;
}Component;

typedef struct
{
    int number[MAXN][MAXN][MAXN];
    int height[MAXN][MAXN];
    int N;
}Tower;

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

void getTower(Tower *tower)
{
    int N;
    scanf("%d", &N);
    tower->N = N;
    for(int level = 1 ; level <= N ; level++){
        for(int i = 0 ; i < level ; i++){
            for(int j = 0 ; j < level ; j++){
                scanf("%d",&(tower->number[i][j][N-level]));
            }
        }
    }
    for(int row = 0 ; row < N ; row++){
        for(int col = 0 ; col < N ; col++){
            tower->height[row][col] = N-max(row, col);
        }
    }
    return;
}

bool inLand(int row, int col, int hei, Tower *tower){
    return(hei > 0 && hei < tower->height[row][col] && row >= 0 && row < (tower->N - tower->height[row][col]) && col >= 0 && col < tower->height[row][col]);
}

Component findMaxComponent(int row, int col, int height, Tower *tower, Component currentComponent)
{

}

int main()
{
    Tower tower;
    getTower(&tower);

    return 0;
}