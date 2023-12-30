#include<stdio.h>
#include<string.h>

#define MAXLEN 100000
#define L 26

int main(){

    char word[MAXLEN+1];
    int frequency[L][L][L] = {{{0}}}; // nice thought!
    while(scanf("%s", word) != EOF){
        //puts(word);
        int length = strlen(word);
        if(length >= 3){
            for(int i = 0 ; i < length - 2 ; i++){
                frequency[word[i] - 'a'][word[i+1] - 'a'][word[i+2] - 'a']++;
            }
        }
    }

    
    for(int times = 0; times < 3 ; times++){
        int max_fre = 0;
        int maxi, maxj, maxk;
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

        printf("%c%c%c\n", maxi+'a', maxj+'a', maxk+'a');
        frequency[maxi][maxj][maxk] = 0;
    }

    return 0;
}