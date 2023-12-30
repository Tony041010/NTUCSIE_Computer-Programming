#include<stdio.h>
#include<assert.h>
#define arraysize 10

main(){

    int m;
    scanf("%d", &m);
    assert(m >= 1 && m < arraysize);

    int n[arraysize];

    for(int i = 0 ; i < arraysize ; i++){
        scanf("%d", &(n[i]));
    }

    // start bubble-sorting
    for(int i = m - 2 ; i >= 0 ; i--){ // decide the range
        for(int j = 0 ; j <= i ; j++){ // sorting
            if(n[j] > n[j+1]){
                int temp = n[j+1];
                n[j+1] = n[j];
                n[j] = temp;
            }
        }
    }

    for(int i = 0 ; i < m ; i++){
        printf("%d\n", n[i]);
    }

}