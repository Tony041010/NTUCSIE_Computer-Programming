#include<stdio.h>
int main(){

    int n, m;
    scanf("%d%d", &n, &m);

    char name[10][64];
    int check[10][256][2] = {{{0}}};
    int checkr[10][2] = {{0}};

    int MAX = m*m+1;
    int row_col_of_numbers[10][MAX][2];

    for(int i = 0 ; i < n ; i++){
        
        scanf("%s", name[i]);
        for(int row = 0; row < m ; row++){
            for(int col = 0 ; col < m ; col++){
                
                // number : 1 ~ m*m
                int number;
                scanf("%d", &number);
                row_col_of_numbers[i][number][0] = row;
                row_col_of_numbers[i][number][1] = col;
                check[i][row][0]++;
                check[i][col][1]++;
                if(row == col){
                    checkr[i][0]++;
                }
                if(row+col == m-1){
                    checkr[i][1]++;
                }
            }
        }
    }
    //printf("Pass dada input process\n");
    // bingoing
    int numbers = m*m;
    int win = 0;
    while(numbers--){
        int number;
        scanf("%d", &number);

        for(int i = 0 ; i < n ; i++){
            int row = row_col_of_numbers[i][number][0];
            int col = row_col_of_numbers[i][number][1];

            check[i][row][0]--;
            check[i][col][1]--;
            //printf("check[i][row][0] %d check[i][col][1] %d", check[i][row][0], check[i][col][1]);
            if(row == col){
                checkr[i][0]--;
            }
            if(row + col == m-1){
                checkr[i][1]--;
            }

            if(check[i][row][0] == 0 || check[i][col][1] == 0 || checkr[i][0] == 0 || checkr[i][1] == 0){
                //printf("Someone won.\n");
                if(win == 0){
                    win++;
                    printf("%d %s", number, name[i]);
                }
                else{
                    printf(" %s", name[i]);
                }
            }
        }
        if(win > 0){
            break;
        }
    }

}