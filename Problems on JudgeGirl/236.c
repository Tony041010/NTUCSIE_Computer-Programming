#include<stdio.h>


int gcd(int a, int b){
    while(a%b != 0){
        int temp = a;
        a = b;
        b = temp%b;
    }
    //printf("GCD %d\n", b);
    return b;
}

int lcm(int a, int b){
    int GCD = gcd(a, b);
    //printf("LCM %d\n", a/GCD * b);
    return a/GCD * b;
}


int main(){

    int number_a, number_b, number_c;
    scanf("%d%d", &number_a, &number_b);
    int LCM = lcm(number_a, number_b);
    while(scanf("%d", &number_c) != EOF){
        LCM = lcm(LCM, number_c);
    }
    printf("%d", LCM);

}