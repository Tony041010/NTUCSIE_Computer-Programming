#include<stdio.h>
#include<stdbool.h>

int main(){

    int n;
    scanf("%d", &n);
    int array[n][n];

    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < n ; c++){
            scanf("%d", &(array[r][c]));
        }
    }

    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {1, 0, -1, 0};
    int row = n/2, col = n/2;
    int direction = 0;

    printf("%d\n", array[row][col]);
    for(int dist = 1; dist < n ; dist++){ //record the dist_th walk
        for(int step = 0; step < ((dist == n-1) ? 3 : 2) ; step++){ //record how many times the walk should do
            for(int i = 0 ; i < dist ; i++){ //counting the squares walked by this time
                row += dr[direction];
                col += dc[direction];
                printf("%d\n", array[row][col]);
            }
            // a loop from 0 to 4 and keep repeating
            direction = (direction+1)%4;
        }
    }
}