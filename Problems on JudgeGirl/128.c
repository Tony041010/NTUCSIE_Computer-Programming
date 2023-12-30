/* intersection.h
void intersection(int map[100][100], int result[4]);
*/

#include<stdio.h>
#include<stdbool.h>


void intersection(int map[100][100], int result[4]){

    for(int i = 0 ; i < 4 ; i++){
        result[i] = 0;
    }

    for(int r = 0 ; r < 100 ; r++){
        for(int c = 0 ; c < 100 ; c++){
            
            if(map[r][c] != 1){
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
                    if(R >= 0 && R <= 100-1 && C >=0 && C <= 100-1){
                        if(map[R][C] == 1){
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
                result[0]++;
                break;
            case 3:
                result[1]++;
                break;
            case 2:
                if(turn_c && turn_r){
                    result[2]++;
                }
                break;
            case 1:
                result[3]++;
                break;
            default:
                break;
            }

        }
        //printf("\n");
    }

}


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
    int result[4] = {0};
    intersection(array, result);

    for(int i = 0 ; i < 4 ; i++){
        printf("%d\n", result[i]);
    }
    
}