#include<stdio.h>
#include<assert.h>

#define  MAXH 500
#define MAXW 500

#define STONE 0
#define QUEEN 1
#define BISHOP 2
#define ROOK 3

void attack(int board[MAXH][MAXW], int dr[4], int dc[4], int row, int col, int R, int C){
    for(int i = 0 ; i < 4 ; i++){
        int r = row + dr[i], c = col + dc[i];
        while(r >= 0 && r < R && c >= 0 && c < C && board[r][c] != 1){
            board[r][c] = 1;
            r += dr[i], c += dc[i];
        }
    }
    board[row][col] = 1;

}

void RookAttack(int board[MAXH][MAXW], int row, int col, int R, int C){

    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    attack(board, dr, dc, row, col, R, C);

}

void BishopAttack(int board[MAXH][MAXW], int row, int col, int R, int C){

    int dr[4] = {1, -1, -1, 1};
    int dc[4] = {1, 1, -1, -1};

    attack(board, dr, dc, row, col, R, C);

}

void QueenAttack(int board[MAXH][MAXW], int row, int col, int R, int C){

    RookAttack(board, row, col, R, C);
    BishopAttack(board, row, col, R, C);
}

int main(){

    int R, C;
    scanf("%d%d", &R, &C);
    int board[MAXH][MAXW];
    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C ; c++){
            board[r][c] = 0;
        }
    }

    int type, row, col;
    while(scanf("%d%d%d", &type, &col, &row) != EOF){

        switch(type){
        case STONE:
            board[row][col] = 1;
            break;
        case QUEEN:
            QueenAttack(board, row, col, R, C);
        case BISHOP:
            BishopAttack(board, row, col, R, C);
            break;
        case ROOK:
            RookAttack(board, row, col, R, C);
            break;
        default:
            printf("Wrong type.\n");
            break;
        }

    }

    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C ; c++){
            if(c == C-1){
                printf("%d", board[r][c]);
            }
            else{
                printf("%d ", board[r][c]);
            }
        }
        printf("\n");
    }

}