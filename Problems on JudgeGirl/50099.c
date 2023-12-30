#include<stdio.h>

/* com : center of mass */
int findCom(long long int seesaw[], int start, int end)
{
    if(end - start < 2){
        return -1;
    }
    for(int com = start ; com <=end ; com++){ /* check if there is a com */
        long long int leftTorque = 0;
        for(int left = start ; left < com ; left++){
            leftTorque += seesaw[left] * (com - left);
        }
        
        long long int rightTorque = 0;
        for(int right = com + 1 ; right <= end ; right++){
            rightTorque += seesaw[right] * (right - com);
        }

        if(leftTorque == rightTorque){
            return com;
        }
    }
    /* not found */
    return -1;
}

void findAllCom(long long int seesaw[], int start, int end)
{

    int com = findCom(seesaw, start, end);
    if(com == -1){
        return;
    }
    
    findAllCom(seesaw, start, com-1); /*left part of all com should be printed first*/
    printf("%d\n", com);
    findAllCom(seesaw, com+1, end);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    long long int seesaw[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &(seesaw[i]));
    }

    findAllCom(seesaw, 0, n-1);
    return 0;
}