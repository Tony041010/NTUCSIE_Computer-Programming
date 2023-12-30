#include<stdio.h>
#include<stdint.h>
#include<limits.h>
#define MAXN 20
#define MAXK 10

uint64_t min(uint64_t a, uint64_t b)
{
    return ((a < b) ? a : b);
}

uint64_t minSumOfSquares(int i, uint64_t numbers[], uint64_t sum[], uint64_t currentSum, int n, int k, uint64_t *best)
{
    if(i >= n){
        *best = min(*best, currentSum);
        return *best;
    }
    if(currentSum >= *best){
        return UINT64_MAX;
    }
    /* (a+b)^2 = a^2 + 2ab + b^2 */
    uint64_t minSum = UINT64_MAX;
    for(int g = 0 ; g < k ; g++){
        uint64_t oldSum = sum[g];
        //printf("currentSum : %lu oldSum : %lu\n", currentSum, oldSum);
        sum[g] += numbers[i];
        minSum = min(minSum, minSumOfSquares(i+1, numbers, sum, currentSum + 2*oldSum*numbers[i] + numbers[i]*numbers[i], n, k, best));
        sum[g] -= numbers[i];
    }
    return minSum;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    uint64_t numbers[MAXN];
    for(int i = 0 ; i < n ; i++){
        scanf("%lu", &(numbers[i]));
    }
    uint64_t sum[MAXK] = {0};
    uint64_t best = UINT64_MAX;
    sum[0] = numbers[0]; /* set a initial state to avoid the first layer of recursion */
    printf("%lu\n", minSumOfSquares(1, numbers, sum, sum[0]*sum[0], n, k, &best));
    return 0;
}