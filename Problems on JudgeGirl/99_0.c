#include<stdio.h>
#include<stdbool.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    char name[10][64];
    int board[10][256][256] = {{{0}}};
    int board_noted[10][256][256] = {{{0}}};
    int idxs[10][2] = {{0}};
    bool is_win[10];
    for(int i = 0 ; i < 10 ; i++){
        is_win[i] = false;
    }

    // input data
    for(int i = 0 ; i < n ; i++){
        scanf("%s", name[i]);
        for(int row = 0; row < m ; row++){
            for(int col = 0 ; col < m ; col++){
                scanf("%d", &(board[i][row][col]));
            }
        }
    }

    // start bingoing
    long long int m_square = m*m;
    int number;
    for(long long int i = 0 ; i < m_square ; i++){
        scanf("%d", &number);
        for(int p = 0 ; p < n ; p++){
            for(int row = 0; row < m ; row++){
                for(int col = 0 ; col < m ; col++){
                    if(board[p][row][col] == number){
                        board_noted[p][row][col] = 1;
                        idxs[p][0]= row, idxs[p][1] = col;
                    }
                }
            }
        }

        if(i >= m-1){

            //check if there're winnners
            //row
            for(int p = 0 ; p < n ; p++){
                for(int col = 0; col < m ; col++){
                    if(board_noted[p][(idxs[p][0])][col] == 1){
                        if(col == m-1){
                            is_win[p] = true;
                        }
                    }
                    else{
                        break;
                    }
                }
            }

            //column
            for(int p = 0 ; p < n ; p++){
                if(is_win[p]){
                    continue;
                }
                for(int row = 0; row < m ; row++){
                    if(board_noted[p][row][idxs[p][1]] == 1){
                        if(row == m-1){
                            is_win[p] = true;
                        }
                    }
                    else{
                        break;
                    }
                }
            }

            //cross
            for(int p = 0 ; p < n ; p++){
                if(is_win[p]){
                    continue;
                }
                if(idxs[p][0] == idxs[p][1]){
                    for(int idx = 0 ; idx < m ; idx++){
                        if(board_noted[p][idx][idx] == 1){
                            if(idx == m-1){
                                is_win[p] = true;
                            }
                            
                        }
                        else{
                            break;
                        }
                    }
                }
                if(idxs[p][0]+idxs[p][1] == m-1){
                    for(int idx = 0 ; idx < m ; idx++){
                        if(board_noted[p][idx][m-1-idx] == 1){
                            if(idx == m-1){
                                is_win[p] = true;
                            }
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        bool is_first_winner = true;
        int last_winner_idx = 0;
        for(int p = 0 ; p <n ; p++){
            if(is_win[p]){
                last_winner_idx = p;
            }
        }
        for(int p = 0 ; p < n ; p++){
            if(is_win[p]){
                if(is_first_winner){
                    is_first_winner = false;
                    printf("%d ", number);
                }
                if(p == last_winner_idx){
                    printf("%s", name[p]);
                }
                else{
                    printf("%s ", name[p]);
                }
            }
        }
        if(!is_first_winner){
            return 0;
        }

    }
    return 0;
}