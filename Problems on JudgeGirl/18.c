#include<stdio.h>
#include<stdbool.h>

int main(){

    int row, col;
    scanf("%d%d", &row, &col);
    int array[100][100] = {{0}};
    for(int r = 0 ; r < row ; r++){
        for(int c = 0 ; c < col ; c++){
            int temp;
            scanf("%d", &temp);
            array[r][c] = temp;
        }
    }

    // start searching
    for(int r = 0 ; r < row ; r++){
        for(int c = 0 ; c < col ; c++){

            bool is_bigger = true;            
            for(int dc = -1; dc <= 1 ; dc++){
                if(!is_bigger){
                    break;
                }
                else{
                    for(int dr = -1 ; dr <= 1 ; dr++){
                        if(dr*dc != 0 || (dr==0 && dc == 0)){
                            continue;
                        }

                        int R = r+dr, C = c+dc;
                        if(R >= 0 && R <= row-1 && C >=0 && C <= col-1){
                            if(array[r][c] <= array[R][C]){
                                is_bigger = false;
                                break;
                            }
                        }
                    }
                }
                
            }

            if(is_bigger){
                printf("%d\n", array[r][c]);
            }

        }
    }

}