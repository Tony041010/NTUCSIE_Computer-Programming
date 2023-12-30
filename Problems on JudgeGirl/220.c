#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(){

    char a;
    char prev_2 = '\0';
    char prev_1 = '\0';
    int nums = 0;
    bool got_peroid = false;
    bool two_blank = false;
    bool nextline = false;
    bool toEOF = false;
    while(1){
        scanf("%c", &a);
        if(a == '.'){
            got_peroid = true;
        }
        if(prev_2 == '.' && prev_1 == ' ' && a == ' '){
            nums++;
        }
        else if(prev_1 == '.' && a == '\n'){
            nums++;
        }
        else if(prev_1 == '.' && a == '\0'){
            nums++;
            break;
        }
        else if(got_peroid && a == '\0'){
            nums++;
            break;
        }

        if(got_peroid && a != ' ' && a != '\0'){
            got_peroid = false;
        }
        prev_2 = prev_1;
        prev_1 = a;
        printf("%c %c %c\n", prev_2, prev_1, a);
    }

    printf("%d\n", nums);
    return 0;

}