/*
#include<stdio.h>
#include<stdbool.h>
 
#define MAXN 20
#define MAXM 5000000
 
int pickNumbers(int i, int numbers[], int k, int N, int M, bool formed)
{
    if(i >= N || M < 0){
        return 0;
    }
    if(k <= 0 && M >= 0 && !formed){
        printf("one way found k %d\n", k);
        return 1 + pickNumbers(i+1, numbers, k-1, N, M-numbers[i], false) + pickNumbers(i+1, numbers, k, N, M, true);
    }
    return pickNumbers(i+1, numbers, k-1, N, M-numbers[i], false) + pickNumbers(i+1, numbers, k, N, M, true);
}
 
 
int main()
{
    int k, N, M;
    scanf("%d%d%d", &k, &N, &M);
 
    int numbers[MAXN];
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &(numbers[i]));
    }
    printf("%d\n", pickNumbers(0, numbers, k, N, M, false));
    return 0;
}
*/


#include<stdio.h>
#include<stdbool.h>
 
#define MAXN 20
#define MAXM 5000000
 
int pickNumbers(int i, int numbers[], int k, int numPicked, int N, int M, int sum)
{
    // consider all kinds of ways.
    // If it fits the rule in the end, then it is valid and we retuen 1; otherwise, it is not valid and we retun 0
    if(i == N){
        return numPicked >= k && sum <= M;
    }
    return pickNumbers(i+1, numbers, k, numPicked+1, N, M, sum+numbers[i]) + pickNumbers(i+1, numbers, k, numPicked, N, M, sum);
}
 
 
int main()
{
    int k, N, M;
    scanf("%d%d%d", &k, &N, &M);
 
    int numbers[MAXN];
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &(numbers[i]));
    }
    printf("%d\n", pickNumbers(0, numbers, k, 0, N, M, 0));
    return 0;
}
