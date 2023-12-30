#include<stdio.h>
#include<stdbool.h>

int main(){

    int W, D;
    scanf("%d%d", &W, &D);

    bool mirror[W][D]; //check where the mirrors are
    for(int d = D-1 ; d >= 0 ; d--){ //because(0, 0) is at the bottom-left, the inputs start from the top-left
        for(int w = 0 ; w < W ; w++){
            int temp;
            scanf("%d", &temp);
            mirror[w][d] = (temp == 1);
        }
    }
    //[up, left, down, right]
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -3, 0};

    int newDir[4] = {3, 2, 1, 0};

    int x, y, dir;
    for(int i = 0 ; i < 2*(W+D) ; i++){
        if(i<W){ // up
            x = i, y = 0, dir = 0;
        }
        else if(i < W+D){ // left
            x = W-1, y = i-W, dir = 1;
        }
        else if(i < 2*W+D){ // down
            x = 2*W - (i-D) - 1, y = D-1 , dir = 2;
        }
        else{
            x = 0, y = 2*D - (i-2*W) - 1, dir = 3;
        }

        while(x >= 0 && x < W && y >= 0 && y < D){
            if(mirror[x][y]){
                dir = newDir[dir];
            }
            x += dx[dir], y += dy[dir];
        }

        if(y < 0){ // at the bottom row
            printf("%d\n", x);
        }
        else if(x >= W){ // at the right column
            printf("%d\n", W+y);
        }
        else if(x < 0){ // at the left column
            printf("%d\n", 2*W + D + (D-y)-1);
        }
        else{ // at the top row
                printf("%d\n", W+D+(W-x)-1);
        }

    }

}