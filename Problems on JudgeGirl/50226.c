#include<stdio.h>

int main(){

    int g1, g2, g3, g4;
    while(scanf("%d%d%d%d", &g1, &g2, &g3, &g4) != EOF){

        //gcd12 lcm12
        int m = g1, n = g2;
        while(m%n != 0){
            int temp = m;
            m = n;
            n = temp%n;
        }
        int gcd12 = n;
        int lcm12 = g1/gcd12*g2;

        //printf("%d %d %d %d\n", g1, g2, gcd12, lcm12);

        //gcd34 lcm34
        m = g3, n = g4;
        while(m%n != 0){
            int temp = m;
            m = n;
            n = temp%n;
        }
        int gcd34 = n;
        int lcm34 = g3/gcd34*g4;

        //printf("%d %d %d %d\n", g3, g4, gcd34, lcm34);

        //gcd1234
        m = lcm12, n = lcm34;
        while(m%n != 0){
            int temp = m;
            m = n;
            n = temp%n;
        }
        int gcd1234 = n;
        int lcm1234 = lcm12/gcd1234*lcm34;

        printf("%d\n", lcm1234/g1);
    }

}