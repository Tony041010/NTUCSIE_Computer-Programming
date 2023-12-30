#include<stdio.h>
#include<string.h>

#define L 26
#define MAXLEN 100000
int main(){

    int frequency[L][L][L] = {{{0}}};

    char word[MAXLEN+1]; // for '\0'

    while(scanf("%s", word) != EOF){
        int length = strlen(word);
        if(length < 3){
            continue;
        }
        else{
            for(int i = 0 ; i < length - 2 ; i++){
                frequency[word[i] - 'a'][word[i+1] - 'a'][word[i+2] - 'a']++;
            }
        }
    }
    int max_fre = 0;
    int maxi, maxj, maxk;
    for(int times = 0 ; times < 3 ; times++){
        for(int i = 0 ; i < L ; i++){
            for(int j = 0 ; j < L ; j++){
                for(int k = 0 ; k < L ; k++){
                    if(frequency[i][j][k] > max_fre){
                        max_fre = frequency[i][j][k];
                        maxi = i;
                        maxj = j;
                        maxk = k;
                    }
                }
            }
        }
        printf("%c%c%c\n", maxi + 'a', maxj + 'a', maxk + 'a');
        frequency[maxi][maxj][maxk] = 0;
        max_fre = 0;
    }

}