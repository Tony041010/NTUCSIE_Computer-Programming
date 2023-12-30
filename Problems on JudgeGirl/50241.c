#include<stdio.h>
#include<stdint.h>
#define MAXN 100000

int main()
{
    int N;
    scanf("%d", &N);
    uint64_t numbers[MAXN];
    for(int i = 0 ; i < N ; i++){
        scanf("%llu", &(numbers[i]));
    }
    char string[12*N+1]; // for '\0'
    for(int i = 0 ; i < N ; i++){
        //printf("number %llu\n", numbers[i]);
        for(int t = 0 ; t < 12 ; t++){
            uint64_t set = ((uint64_t)31 << (t*5));
            uint64_t trans = ((numbers[i] & set)>>(t*5));
            //printf("%llu %llu\n", set, trans);
            //printf("%c\n", (trans+'a'));
            string[i*12 + t] = (trans + 'a');
        }
    }
    string[12*N] = '\0';
    printf("%s\n", string);
    return 0;
}