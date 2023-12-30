#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAXJ 500
#define MAXM 500
#define MAXTPERJOB 500

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(){

    int M, J;
    scanf("%d%d", &M, &J);

    int Jready[MAXJ];
    int numTask[MAXJ];

    int totalTask = 0;
    int machine[MAXJ][MAXTPERJOB];
    int time[MAXJ][MAXTPERJOB];

    for(int j = 0 ; j < J ; j++){
        scanf("%d%d", &(Jready[j]), &(numTask[j]));
    
        for(int t = 0 ; t < numTask[j] ; t++){
            scanf("%d%d", &(machine[j][t]), &(time[j][t]));
        }
        totalTask += numTask[j];
    }

    int curretTask[MAXJ] = {0}; 
    int Mready[MAXM] = {0};
    for(int i = 0 ; i < totalTask ; i++){
        int ECtime = INT_MAX; //Earliest completion time
        int ECmachine;
        int ECjob = -1;

        for(int j = 0 ; j < J ; j++){
            if(curretTask[j] < numTask[j]){
                int task = curretTask[j];
                int Completion = max(Jready[j], Mready[machine[j][task]])+time[j][task];
            
                if(Completion < ECtime){
                    ECtime = Completion;
                    ECjob = j;
                    ECmachine = machine[j][task];
                }
            }
        }

        Jready[ECjob] = ECtime;
        Mready[ECmachine] = ECtime;
        curretTask[ECjob]++;
    }

    for(int j = 0 ; j < J ; j++){
        printf("%d\n", Jready[j]);
    }

}