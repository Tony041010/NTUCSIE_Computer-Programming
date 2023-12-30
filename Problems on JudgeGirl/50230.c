#include<stdio.h>
#include<stdbool.h>

int main(){

    int S, C;
    scanf("%d%d", &S, &C);
    int HashTable[S][C];

    for(int s = 0 ; s < S ; s++){
        for(int c = 0 ; c < C ; c++){
            HashTable[s][c] = 0;
        }
    }
    //printf("time to the table.\n");
    int k;
    while(scanf("%d", &k) != EOF){

        int f_k = (77*k + 2222) % S;
        bool is_found = false;
        for(int c = 0 ; c < C ; c++){
            if(HashTable[f_k][c] == k){
                printf("%d %d\n", k, f_k);
                HashTable[f_k][c] = 0;
                is_found = true;
                break;
            }
        }
        if(!is_found){
            for(int c = 0 ; c < C ; c++){
                if(HashTable[f_k][c] == 0){
                    HashTable[f_k][c] = k;
                    //printf("%d %d %d\n", f_k, c, k);
                    break;
                }
            }
        }

    }

}