#include<stdio.h>
#include<stdint.h>

int main(){

    int width, height;
    scanf("%d%d", &width, &height);
    char one, zero;
    scanf("\n%c %c", &one, &zero);
    //printf("A%cand%cB\n", one, zero);
    int bits = width*height;
    int nums = (bits%32 == 0) ? (bits/32) : (bits/32)+1;
    //printf("bits %d nums %d\n", bits, nums);
    uint32_t number;
    int times = 0;
    for(int i = 0 ; i < nums ; i++){
        scanf("%u", &number);
        for(int j = 0 ; j < sizeof(uint32_t)*8 && bits > 0 ; j++, bits--, times++){
            uint32_t t = (1<<(31-j));
            uint32_t and = number&t;
            //printf("t %d\n", t);
            //printf("%u\n", and);
            if(and == 0){
                printf("%c", zero);
            }
            else{
                printf("%c", one);
            }

            if(times % width == width-1){
                printf("\n");
            }
        }
    }

}