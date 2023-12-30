#include<stdio.h>
#include<stdbool.h>

#define MAZESIZE 100

bool inMaze(int row, int col, int n, int m){
    return (row >= 0 && row < n && col >= 0 && col < m);
}

bool goMaze(int maze[MAZESIZE][MAZESIZE], int step, int currentRow, int currentCol, int endRow, int endCol, int n, int m){

    if(currentRow == endRow && currentCol == endCol){
        return true;
    }
    int dRow[4] = {1, 0, -1, 0}; // up right down left
    int dCol[4] = {0, 1, 0, -1};

    for(int d = 0 ; d < 4 ; d++){ // try four directions
        int nextRow = currentRow + dRow[d];
        int nextCol = currentCol + dCol[d];
        if(inMaze(nextRow, nextCol, n, m) && maze[nextRow][nextCol] == 0){ // if we can walk on the next block
            maze[nextRow][nextCol] = step;
            if(goMaze(maze, step+1, nextRow, nextCol, endRow, endCol, n, m)){ // if that route can lead us to the endpoint
                return true;
            }
            maze[nextRow][nextCol] = 0; // wrong try, we clear our step on this block
        }
    }
    return false; // tried 4 directions but still fail -> backtrack
}

int main(){

    int n, m;
    scanf("%d%d", &n, &m);
    int maze[MAZESIZE][MAZESIZE];
    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < m ; c++){
            scanf("%d", &(maze[r][c]));
        }
    }
    int startRow, startCol;
    int endRow, endCol;
    scanf("%d%d", &startRow, &startCol);
    scanf("%d%d", &endRow, &endCol);

    maze[startRow][startCol] = 1;
    goMaze(maze, 2, startRow, startCol, endRow, endCol, n, m);
    
    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < m ; c++){
            printf("%2d ", maze[r][c]);
        }
        printf("\n");
    }
    return 0;
}