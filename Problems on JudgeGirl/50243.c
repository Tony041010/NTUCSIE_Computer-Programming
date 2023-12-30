#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

#define BITS 64

typedef struct
{
    int num;
    uint64_t selected;
}Selection;

bool coverAll(const Selection selection, const uint64_t neighbor[], const int n)
{
    for(int i = 0 ; i < n ; i++){
        if(selection.selected & ((uint64_t)1 << i)){ // is chosen
            continue;
        }
        if(neighbor[i] & ~(selection.selected)){ // not chosen -> all of its friend should be chosen; otherwise, it's not fully cover (stricter condition)
            return false;
        }
    }
    return true;
}

void printSelection(const Selection selection, const int n)
{
    for(int i = 0 ; i < n ; i++){
        if(selection.selected & ((uint64_t)1 << i)){
            printf("%d\n", i);
        }
    }
}

Selection friendCover(const uint64_t neighbor[], const int i, const int n, const uint64_t hasNeighbor, const Selection selection)
{
    if(coverAll(selection, neighbor, n)){
        return selection;
    }
    Selection noSolution = {INT_MAX, 0};
    if(i >= n){
        return noSolution;
    }

    if((hasNeighbor & ((uint64_t)1 << i)) == 0){ /* that person doesn't have any friends :( */
        return friendCover(neighbor, i+1, n, hasNeighbor, selection);
    }

    Selection add = {selection.num+1, selection.selected | ((uint64_t)1 << i)};
    Selection choose = friendCover(neighbor, i+1, n, hasNeighbor, add);
    Selection noChoose = friendCover(neighbor, i+1, n, hasNeighbor, selection);
    return (noChoose.num < choose.num) ? noChoose : choose;
}

int main()
{
    /* n : from 0-th to n-1th */
    int n, m;
    scanf("%d%d", &n, &m);

    uint64_t neighbor[BITS] = {0};
    uint64_t hasNeighbor = 0;

    uint64_t bit[n];
    for(int i  = 0 ; i < n ; i++){
        bit[i] = ((uint64_t)1 << i);
    }

    for(int i = 0 ; i < m ; i++){
        int friendA, friendB;
        scanf("%d%d", &friendA, &friendB);
        neighbor[friendA] |= bit[friendB];
        neighbor[friendB] |= bit[friendA];
        hasNeighbor |= (bit[friendA] | bit[friendB]);
    }
    //printf("%d\n", hasNeighbor);

    Selection selected = {0, 0};
    Selection minCover = friendCover(neighbor, 0, n, hasNeighbor, selected);
    printSelection(minCover, n);
    
    return 0;
}