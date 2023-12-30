#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAXN 14

int min(int a, int b){
    return (a < b) ? a : b;
}

int shortestCycle(int dist[MAXN][MAXN], bool visited[MAXN], int citiesLeft, int cost, int now, int N, int *best){
    if(citiesLeft == 0){ // finish one travel
        *best = min(*best, cost+dist[now][0]);
        return (cost + dist[now][0]); // return its own cost(not *best)
    }
    if(cost >= *best){
        return INT_MAX;
    }
    
    int minDistance = INT_MAX;
    for(int next = 1 ; next < N ; next++){
        if(visited[next] == 0){ /* not visited yet */
            visited[next] = true;
            int distance = shortestCycle(dist, visited, citiesLeft-1, cost+dist[now][next], next, N, best);
            minDistance = min(distance, minDistance);
            visited[next] = false;
        }
    }
    return minDistance;
}

int main(){

    int N;
    scanf("%d", &N);
    int dist[MAXN][MAXN];
    /* distance[i][j] = the distance between city i and city j */
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d", &(dist[i][j]));
        }
    }

    bool visited[MAXN] = {false};
    //visited[0] = true;
    int best = INT_MAX;
    printf("%d\n", shortestCycle(dist, visited, N-1, 0, 0, N, &best)); // start from city 0
    return 0;
}