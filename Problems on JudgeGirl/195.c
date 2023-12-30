#include<stdio.h>
#include<stdbool.h>

int main(){

    int N;
    scanf("%d", &N);
    int Board[3][3] = {{0}};
    bool is_black = true;
    if(N == 0){
        printf("There is a draw.\n");
        return 0;
    }
    for(int i = 1 ; i <= N ; i++){

        int row, col;
        scanf("%d%d", &row, &col);
        if(row < 0 || row >= 3 || col < 0 || col >= 3 || Board[row][col] != 0){
            if(i != N){
                continue;
            }
            else{
                printf("There is a draw.\n");
                break;
            }
        }

        Board[row][col] = (is_black) ? 1 : 2;

        // Check!
        // row
        bool is_win_row = true;
        for(int c = 0; c <= 2 ; c++){
            if(is_black){
                if(Board[row][c] != 1){
                    is_win_row = false;
                    break;
                }
            }
            else{
                if(Board[row][c] != 2){
                    is_win_row = false;
                    break;
                }

            }
        }

        //column
        bool is_win_col = true;
        for(int r = 0; r <= 2 ; r++){
            if(is_black){
                if(Board[r][col] != 1){
                    is_win_col = false;
                    break;
                }
            }
            else{
                if(Board[r][col] != 2){
                    is_win_col = false;
                    break;
                }

            }
        }

        //cross
        bool is_win_cross = false;
        //1st 
        if(Board[0][0] == Board[1][1]  && Board[0][0] == Board[2][2] && Board[0][0] != 0){
            is_win_cross = true;
        }
        if(Board[0][2] == Board[1][1]  && Board[0][2] == Board[2][0] && Board[0][2] != 0){
            is_win_cross = true;
        }


        //printf("%d %d %d ", is_win_row, is_win_col, is_win_cross);
        //determine who wins
        if(is_win_row || is_win_col || is_win_cross){
            if(is_black){
                printf("Black wins.\n");
                break;
            }
            else{
                printf("White wins.\n");
                break;
            }
        }
        if(i == N){
            printf("There is a draw.\n");
        }

        is_black = (is_black) ? false : true;
        //printf("%d\n", is_black);
    }

}
// black = 1, white = 2
// in x y
// determine
// put
// check


// 00 01 02
// 10 11 12
// 20 21 22