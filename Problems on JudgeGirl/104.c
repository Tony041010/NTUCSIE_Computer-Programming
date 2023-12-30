#include<stdio.h>
#include<stdbool.h>

bool canUseUp(int a, int b, int c, int DA, int DB, int DC, int EA, int EB, int EC, int FA, int FB, int FC){
    if(a == 0 && b == 0 && c == 0){
        return true;
    }
    else if(a < 0 || b < 0 || c < 0){
        return false;
    }
    else{
        return (canUseUp(a-DA, b-DB, c-DC, DA, DB, DC, EA, EB, EC, FA, FB, FC) 
                || canUseUp(a-EA, b-EB, c-EC, DA, DB, DC, EA, EB, EC, FA, FB, FC) 
                || canUseUp(a-FA, b-FB, c-FC, DA, DB, DC, EA, EB, EC, FA, FB, FC));
    }
}

bool execute(int n, int N, int DA, int DB, int DC, int EA, int EB, int EC, int FA, int FB, int FC){
    if(n >= N){
        return false;
    }
    else{
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(canUseUp(a, b, c, DA, DB, DC, EA, EB, EC, FA, FB, FC)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
        execute(n+1, N, DA, DB, DC, EA, EB, EC, FA, FB, FC);
    }
}

int main(){

    int DA, DB, DC;
    int EA, EB, EC;
    int FA, FB, FC;
    scanf("%d%d%d", &DA, &DB, &DC);
    scanf("%d%d%d", &EA, &EB, &EC);
    scanf("%d%d%d", &FA, &FB, &FC);

    int n;
    scanf("%d", &n);
    execute(0, n, DA, DB, DC, EA, EB, EC, FA, FB, FC);

    return 0;
}