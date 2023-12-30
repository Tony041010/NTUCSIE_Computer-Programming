#include<stdio.h>

#define MAXN 100000

int max_3(int a, int b, int c){
    int M = (a>b) ? a : b;
    return (M > c) ? M : c;
}

int highest(int height[MAXN], int position){
    return max_3(height[position], height[position+1], height[position+2]);
    
}

int is_flat(int height[MAXN], int position){
    return (height[position] == height[position+1] && height[position+1] == height[position+2]);
}

int main(){

    int N;
    scanf("%d", &N);
    int height[MAXN] = {0};

    int position, type;
    while(scanf("%d%d", &position, &type) != EOF){

        switch(type){
            case 0:
                if(is_flat(height, position)){
                    height[position] += 2;
                    height[position+1] += 2;
                    height[position+2] += 1;
                }
                else{
                    if(height[position] > height[position+1] && height[position] > height[position+2]){
                        height[position]+=1;
                        height[position+1] = height[position];
                        height[position+2] = height[position]-1;
                    }
                    else{
                        int H = highest(height, position);
                        height[position] = H+2;
                        height[position+1] = H+2;
                        height[position+2] = H+1;
                    }
                    
                }
                break;
            case 1:
                if(is_flat(height, position)){
                    height[position]+=1;
                    height[position+1]+=2;
                    height[position+2]+=2;
                }
                else{
                    if(height[position+2] > height[position+1] && height[position+2] > height[position]){
                        height[position+2]+=1;
                        height[position+1] = height[position+2];
                        height[position] = height[position+2]-1;
                    }
                    else{
                        int H = highest(height, position);
                        height[position+2] = H+2;
                        height[position+1] = H+2;
                        height[position] = H+1;
                    }
                    
                }
                break;
            case 2:
                if(is_flat(height, position)){
                    height[position]+= 1;
                    height[position+1]+= 2;
                    height[position+2] += 1;
                }
                else{
                    int H = highest(height, position);
                    height[position] = H+1;
                    height[position+1] = H+2;
                    height[position+2] = H+1;
                    
                }
                break;
            case 3:
                if(is_flat(height, position)){
                    height[position]+= 2;
                    height[position+1]+= 2;
                    height[position+2] += 2;
                }
                else{
                    int H = highest(height, position);
                    if(H > height[position+1]){
                        height[position] = H+1;
                        height[position+1] = H+1;
                        height[position+2] = H+1;
                    }
                    else{
                        height[position] = H+2;
                        height[position+1] = H+2;
                        height[position+2] = H+2;
                        
                    }
                }
                break;

            default:
                printf("wrong type\n");
                break;
        }
        /*for(int i = 0 ; i < N ; i++){
            if(i == N-1){
                printf("%d\n", height[i]);
            }
            else{
                printf("%d ", height[i]);
            }
        }*/
    }
    for(int i = 0 ; i < N ; i++){
        if(i == N-1){
            printf("%d\n", height[i]);
        }
        else{
            printf("%d ", height[i]);
        }
    }
    

}