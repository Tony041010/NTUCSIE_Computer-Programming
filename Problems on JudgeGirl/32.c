#include<stdio.h>

#define MAX 100

int is_pali(int start, int end, int array[MAX]){
    int e = end;
    for(int s = start ; s <= end ; s++){
        if(array[s] != array[e]){
            return 0;
        }
        else{
            e--;
        }
    }
    return 1;
}

int main(){

    int array[MAX];
    int n = 0;
    while(scanf("%d", &(array[n]))!= EOF){
        n++;
    }

    int first_s = 0, first_e = 0;
    int second_s = 0 , second_e = 0;
    int longest = 0;

    for(int s1 = 0 ; s1 < n ; s1++){
        for(int e1 = s1 ; e1 < n ; e1++){
            if(is_pali(s1, e1, array)){

                // find the second one
                int s2 = e1+1;
                for(int e2 = s2 ; e2 < n ; e2++){
                    if(is_pali(s2, e2, array)){
                        int length = e2-s1+1;
                        if(length >= longest){
                            first_s = s1;
                            first_e = e1;
                            second_s = s2;
                            second_e = e2;
                            longest = length;

                            //printf("%d %d\n", first_s, second_e);
                        }
                    }
                }
            }
        }
    }
    for(int i = first_s ; i <= second_e ; i++){
        if(i == second_e){
            printf("%d", array[i]);
        }
        else{
            printf("%d ", array[i]);
        }
    }

}