#include<stdio.h>
#include<string.h>
#define MAXS 100

int main(){

    char str[MAXS];
    int times[26] = {0};

    scanf("%s", str);

    for(int i = 0 ; i < strlen(str) ; i++){
        //printf("%c\n", str[i]);
        if((str[i] - 'a' >= 0 && str[i] - 'a' < 26) || (str[i] - 'A' >= 0 && str[i] - 'A' < 26)){
            //printf("%c\n", str[i]);
            int idx = (str[i] - 'a' >= 0) ? str[i] - 'a' : str[i] - 'A';
            times[idx]++;
        }
    }
    for(int i = 0 ; i < 26 ; i++){
        printf("%d\n", times[i]);
    }
    

}