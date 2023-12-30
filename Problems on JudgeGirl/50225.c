/*
#include<stdio.h>
 
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int i=1, a=0;
    for(int j=n+m-1; a+j<k; a+=j, j-=2, i++) continue;
    int x=i, y=i;
    if(k-a > m-i+1) x += k-(a+(m-i+1));
    else y += k-a-1;
    printf("%d %d\n", x, y);
}
*/ 

#include<stdio.h>

int main(){

    int N, M, k;
    scanf("%d%d%d", &N, &M, &k);
    int counted_sets = 1, _th = 0;
    for(int nums_of_a_set = N+M-1 ; _th + nums_of_a_set < k ;  _th += nums_of_a_set, nums_of_a_set -= 2, counted_sets++){
        continue; // examine which set is the k_th element in.
    }

    int R = counted_sets, C = counted_sets; //row columnS
    // examine if the k_th element is in the row-part of a set
    if(k-_th > M - counted_sets + 1){
        R += k-(_th + (M-counted_sets + 1));
    }
    else{ // the k_th element is in the column-part of a set
        C += k-(_th+1);
    }
    printf("%d %d\n", R, C);
}