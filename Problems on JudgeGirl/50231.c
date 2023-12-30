#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXC 10
#define MAXN 105
#define MAXS (MAXN*MAXN)
#define KEY 0
#define TINDEX 1

int max(int a, int b){
    return ((a > b) ? a : b);
}

void GetTower(int N, int tower[MAXN][MAXN][MAXN]){

    for(int layer = 1; layer <= N ; layer++){
        for(int row = 0 ; row < layer ; row++){
            for(int col = 0 ; col < layer ; col++){
                //scanf("%d", &(tower[row][col][N-layer]));
                assert(scanf("%d", &(tower[row][col][N-layer])) == 1);
            }
        }
    }

}

void ComputeHeight(int N, int height[MAXN][MAXN]){

    for(int row = 0 ; row < N ; row++){
        for(int col = 0 ; col < N ; col++){
            height[row][col] = N - max(row, col);
        }
    }
}

int GetKey(int tower[MAXN][MAXN][MAXN], int height[MAXN][MAXN], int row, int col){

    assert(height[row][col] > 0);
    return tower[row][col][height[row][col]-1];

}

int f(int key, int S){
    return (77*key + 2222) % S;
}

int FindRemove(int HashTable[MAXS][MAXC][2], int key, int S, int C){
    
    int f_key = f(key, S);
    for(int c = 0 ; c < C ; c++){
        if(HashTable[f_key][c][KEY] == key){
            //printf("Found %d idx %d\n", key, HashTable[f_key][c][TINDEX]);
            HashTable[f_key][c][KEY] = 0;
            return HashTable[f_key][c][TINDEX];
        }
    }
    return -1;

}

void insert(int HashTable[MAXS][MAXC][2], int key, int S, int C, int tindex){
    
    int f_key = f(key, S);
    for(int c = 0 ; c < C ; c++){
        if(HashTable[f_key][c][KEY] == 0){
            HashTable[f_key][c][KEY] = key;
            HashTable[f_key][c][TINDEX] = tindex;
            //printf("Insert %d %d\n", key, tindex);
            return;
        }
    }
    printf("no space found.\n");
    exit(-1);
}

void pairing(int pair[2], int HashTable[MAXS][MAXC][2], int tower[MAXN][MAXN][MAXN], int height[MAXN][MAXN], int row[2], int col[2], int S, int C, int matchindex[2], int pairindex[2]){

    for(int i = 0 ; i < 2 ; i++){
        pair[i] = 0;
        if(height[row[i]][col[i]] > 0){
            int key = GetKey(tower, height, row[i], col[i]);
            int match_tindex = FindRemove(HashTable, key, S, C);
            if(match_tindex == -1){
                insert(HashTable, key, S, C, matchindex[i]);
            }
            else{
                pair[i] = 1;
                pairindex[i] = match_tindex;
            }    
        } 
    }
}

int main(){
    //printf("Hi\n");
    int N, S, C;
    scanf("%d%d%d", &N, &S, &C);
    //printf("NSC\n");

    int tower[MAXN][MAXN][MAXN];
    GetTower(N, tower);

    int height[MAXN][MAXN];
    ComputeHeight(N, height);

    int HashTable[MAXS][MAXC][2] = {{{0}}};
    int tindex = 0;
    int paired = 0;
    int matchindex[2] = {0};
    for(int row = 0 ; row < N ; row++){
        for(int col = 0 ; col < N ; col++, tindex++){

            int key = GetKey(tower, height, row, col);
            //printf("Key %d\n", key);
            int match_tindex = FindRemove(HashTable, key, S, C);
            if(match_tindex == -1){
                insert(HashTable, key, S, C, tindex);
            }
            else{
                paired++;
                matchindex[0] = match_tindex;
                matchindex[1] = tindex;
            }
            //printf("matchindex %d\n", match_tindex);
        }
    }
    //printf("start removing\n");
    //printf("%d %d %d\n", paired, matchindex[0], matchindex[1]);
    assert(paired <= 1);
    bool first = true;
    
    while(paired > 0){

        int row[2] = {matchindex[0] / N, matchindex[1] / N};
        int col[2] = {matchindex[0] % N, matchindex[1] % N};

        int key1 = GetKey(tower, height, row[0], col[0]);
        int key2 = GetKey(tower, height, row[1], col[1]);
        assert(key1 == key2);
        if(first){
            printf("%d", key1);
            first = false;
        }
        else{
            printf(" %d", key1);
        }
        paired=0;
        // remove
        height[row[0]][col[0]]--;
        height[row[1]][col[1]]--;
        
        if(height[row[0]][col[0]] > 0 && height[row[1]][col[1]] > 0 && GetKey(tower, height, row[0], col[0]) == GetKey(tower, height, row[1], col[1])){
            paired++;
            continue;
        }
        else{

            int pair[2];
            int pairindex[2] = {0};
            pairing(pair, HashTable, tower, height, row, col, S, C, matchindex, pairindex);
            paired = pair[0]+pair[1];
            //printf("pair %d %d\n", pair[0], pair[1]);
            //printf("paired %d\n", paired);
            assert(paired <= 1);
            if(paired > 0){
                if(pair[0] == 1){
                    matchindex[1] = pairindex[0];
                }
                else{
                    matchindex[0] = pairindex[1];
                }
            }

        }
    }
    printf("\n");
    return 0;

}