#include<stdio.h>
#include<stdbool.h>

int main(){

    int n;
    scanf("%d", &n);
    int row = n, col = n;
    int array[100][100] = {{0}};
    for(int r = 0 ; r < row ; r++){
        for(int c = 0 ; c < col ; c++){
            int temp;
            scanf("%d", &temp);
            array[r][c] = temp;
        }
    }

    // start searching
    int inter = 0, T_jun = 0, turn = 0, dead_end = 0;
    for(int r = 0 ; r < row ; r++){
        for(int c = 0 ; c < col ; c++){
            
            if(array[r][c] != 1){
                continue;
            }
            int neighbors = 0;
            bool turn_r = false, turn_c = false;         
            for(int dc = -1; dc <= 1 ; dc++){
                for(int dr = -1 ; dr <= 1 ; dr++){
                    if(dr*dc != 0 || (dr==0 && dc == 0)){
                        continue;
                    }
                    int R = r+dr, C = c+dc;
                    if(R >= 0 && R <= row-1 && C >=0 && C <= col-1){
                        if(array[R][C] == 1){
                            neighbors++;
                            if(dr == 0){
                                turn_r = true;
                            }
                            else if(dc == 0){
                                turn_c = true;
                            }
                        }
                    }
                }
            }
            //printf("%d ", neighbors);
            switch(neighbors){
            case 4:
                inter++;
                break;
            case 3:
                T_jun++;
                break;
            case 2:
                if(turn_c && turn_r){
                    turn++;
                }
                break;
            case 1:
                dead_end++;
                break;
            default:
                break;
            }

        }
        //printf("\n");
    }
    printf("%d\n%d\n%d\n%d\n", inter, T_jun, turn, dead_end);

}