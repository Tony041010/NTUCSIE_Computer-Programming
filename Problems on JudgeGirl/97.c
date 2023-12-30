#include<stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    int lots[30] = {0}; //store the info of lots.
    for(int i = 0 ; i < 3*n ; i+=3){
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        lots[i] = x, lots[i+1] = y, lots[i+2] = c;
    }
    int m;
    scanf("%d", &m);
    int bikes[200000] = {0}; //store the info of bikes.
    for(int i = 0 ; i < 2*m ; i+=2){
        int x, y;
        scanf("%d%d", &x, &y);
        bikes[i] = x, bikes[i+1] = y;
    }
    int moved[10] = {0}; //record the number of parked bikes in each lot.
    for(int i = 0 ; i < 2*m ; i+=2){
        int min_distance = 40000, index = 3*m, id_x = 10000, id_y = 10000;
        
        //decide which lot to park
        for(int j = 0 ; j < 3*n ; j+=3){
            if(lots[j+2] == 0){
                continue;
            }
            else{
                int dis_x = bikes[i]-lots[j];
                dis_x = (dis_x>0) ? dis_x : -dis_x;
                int dis_y = bikes[i+1]-lots[j+1];
                dis_y = (dis_y>0) ? dis_y : -dis_y;

                int distance = dis_x + dis_y;

                if(distance < min_distance){
                    min_distance = distance;
                    index = j, id_x = lots[j], id_y = lots[j+1];
                }
                else if(distance == min_distance){
                    if(lots[j] < id_x || (lots[j] == id_x && lots[j+1] < id_y)){
                        min_distance = distance;
                        index = j, id_x = lots[j], id_y = lots[j+1];
                    }
                }
            }
            
        }

        //printf("%d %d\n", index, lots[index+2]);
        //park the bike
        lots[index+2]--;
        //printf("%d %d\n", index, lots[index+2]);
        moved[index/3] ++;
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d\n", moved[i]);
    }

}