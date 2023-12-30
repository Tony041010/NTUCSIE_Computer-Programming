#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<assert.h>

#define MAXN 105
#define MAXLEN 6
#define MAXK MAXN*MAXN
#define C 10

int max(int a, int b){
    return (a > b) ? a : b;
}

int f(char *key, int N){
    int K = N*N;
    int length = strlen(key);
    int sum = key[0] - 'a' + 1;
    for(int i = 1 ; i < length ; i++){
        sum *= 29;
        sum += (key[i] - 'a' + 1);
    }
    return sum % K;
}

void GetTower(char tower[MAXN][MAXN][MAXN][MAXLEN], int N){
    for(int i = 1 ; i <= N ; i++){
        for(int r = 0 ; r < i ; r++){
            for(int c = 0 ; c < i ; c++){
                scanf("%s", tower[r][c][N-i]);
            }
        }
    }
}

void GetHeight(int height[MAXN][MAXN], int N){
    for(int r = 0 ; r < N ; r++){
        for(int c = 0 ; c < N ; c++){
            height[r][c] = N - max(r, c);
        }
    }
}

char *GetKey(char tower[MAXN][MAXN][MAXN][MAXLEN], int height[MAXN][MAXN], int row, int col){
    return tower[row][col][height[row][col]-1];
}

int FindRemove(char *key, int HashTable[MAXK][C], char wordHashTable[MAXK][C][MAXLEN], int N){
    int value = f(key, N);
    for(int c = 0 ; c < C ; c++){
        if(wordHashTable[value][c][0] != '\0' &&  strcmp(wordHashTable[value][c], key) == 0){
            wordHashTable[value][c][0] = '\0'; // clear the key;
            return HashTable[value][c];
        }
    }
    return -1; // not found
}

void Insert(char *key, int HashTable[MAXK][C], char wordHashTable[MAXK][C][MAXLEN], int N, int tindex){
    int value = f(key, N);
    for(int c = 0 ; c < C ; c++){
        if(wordHashTable[value][c][0] == '\0'){
            strcpy(wordHashTable[value][c], key);
            HashTable[value][c] = tindex;
            return;
        }
    }
}

void Pairing(char tower[MAXN][MAXN][MAXN][MAXLEN], int height[MAXN][MAXN], int row[2], int col[2], int HashTable[MAXK][C], char wordHashTable[MAXK][C][MAXLEN], int N, int match_idx[2], int pair_idx[2], int pair[2]){

    for(int times = 0 ; times < 2 ; times++){
        pair[times] = 0;
        pair_idx[times] = -1;
        if(height[row[times]][col[times]] > 0){
            char *key = GetKey(tower, height, row[times], col[times]);
            int match_index = FindRemove(key, HashTable, wordHashTable, N);
            if(match_index == -1){
                Insert(key, HashTable, wordHashTable, N, match_idx[times]);
            }
            else{
                pair[times] = 1;
                pair_idx[times] = match_index;
            }   
        }
    }
}


int main(){
 
    int N;
    scanf("%d", &N);
    int K = N*N;

    // init
    char tower[MAXN][MAXN][MAXN][MAXLEN];
    GetTower(tower, N);

    int height[MAXN][MAXN];
    GetHeight(height, N);

    int HashTable[MAXK][C] = {{0}};
    char wordHashTable[MAXK][C][MAXLEN];
    for(int i = 0 ; i < K ; i++){
        for(int j = 0 ; j < C ; j++){
            wordHashTable[i][j][0] = '\0';
        }
    }


    int tindex = 0;
    int paired = 0;
    int match_idx[2];
    int match_index, match_tindex;
    for(int r = 0 ; r < N ; r++){
        for(int c = 0 ; c < N ; c++, tindex++){
            char *key = GetKey(tower, height, r, c);
            match_index = FindRemove(key, HashTable, wordHashTable, N);
            if(match_index == -1){
                Insert(key, HashTable, wordHashTable, N, tindex);
            }
            else{
                paired++;
                match_idx[0]= match_index;
                match_idx[1] = tindex;
            }
        }
    }
    
    assert(paired <= 1);

    while(paired > 0){
        paired = 0;
        int row[2] = {match_idx[0] / N, match_idx[1] / N};
        int col[2] = {match_idx[0] % N, match_idx[1] % N};
        
        char *key1 = GetKey(tower, height, row[0], col[0]);
        char *key2 = GetKey(tower, height, row[1], col[1]);
        assert(strcmp(key1, key2)== 0);
        printf("%s\n", key1);
        
        height[row[0]][col[0]]--;
        height[row[1]][col[1]]--;
        if(height[row[0]][col[0]] > 0 && height[row[1]][col[1]] > 0 && strcmp(GetKey(tower, height, row[0], col[0]), GetKey(tower, height, row[1],col[1])) == 0){
            paired = 1;
            continue;
        }
        int pair[2];
        int pair_index[2];

        Pairing(tower, height, row, col, HashTable, wordHashTable, N, match_idx, pair_index, pair);

        paired = pair[0] + pair[1];
        assert(paired <= 1);
        if(paired > 0){
            if(pair[0] == 1){
                match_idx[1] = pair_index[0];
            }
            else{
                match_idx[0] = pair_index[1];
            }
        }
    }

    return 0;
}