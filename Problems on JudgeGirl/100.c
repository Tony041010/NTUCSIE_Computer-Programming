/* snake.h
void snake(const int *ptr_array[100][100], int m);
*/

#include <stdio.h>
#include <assert.h>

// sorting : 
/*
0 ~ m-1
m ~ 2m-1
2m ~ 3m-1
...
*/
void snake(const int *ptr_array[100][100], int m){

    int MAX = m*m;

    for(int N = MAX - 1; N >= 1 ; N--){
        for(int i = 0 ; i <= N/m ; i++){
            int END;
            if(i == N/m){
                END = N%m;
            }
            else{
                END = m-1;
            }
            for(int j = 0 ; j <= END ; j++){
                if(i == m-1 && j == END){
                    break;
                }
                else{
                    if(j == END){
                        int A = *ptr_array[i][j];
                        int B = *ptr_array[i+1][0];
                        if(A > B){
                            int *temp = ptr_array[i+1][0];
                            ptr_array[i+1][0] = ptr_array[i][j];
                            ptr_array[i][j] = temp;
                        }
                    }
                    else{
                        int A = *ptr_array[i][j];
                        int B = *ptr_array[i][j+1];
                        if(A > B){
                            int *temp = ptr_array[i][j+1];
                            ptr_array[i][j+1] = ptr_array[i][j];
                            ptr_array[i][j] = temp;
                        }

                    }
                }
            }
        }
    }


    // print this shit out
    for(int i = 0 ; i < m ; i++){
        if(i % 2 == 1){
            for(int j = 0 ; j < m/2 ; j++){
                int *temp = ptr_array[i][m-1-j];
                ptr_array[i][m-1-j] = ptr_array[i][j];
                ptr_array[i][j] = temp;
            }
        }
    }
    
    
}
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}