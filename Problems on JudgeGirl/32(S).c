#include <stdio.h>
#include <stdbool.h>
int check_pali(int start,int end,int arr[]){
    int flag = 1;
    int j=end;
    for(int i=start;i<=end;i++){
        if(arr[i]!=arr[j])
            return 0;
        else
            j--;
    }
    return 1;
}
void dump_array(int start,int end,int arr[]){
    for(int i=start;i<=end;i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    int arr[100], n=0;
    while(scanf("%d",&arr[n])!=EOF){n++;}
    int first_s, first_e;
    int second_s, second_e;
    int largest = 0;
    for(int s1=0;s1<n;s1++){ // find the first pali
        for(int e1=s1;e1<n;e1++){
            if(check_pali(s1,e1,arr)){
                int s2 = e1+1;
                for(int e2=s2;e2<n;e2++){ // find the second pali
                    if(check_pali(s2,e2,arr)){
                        int len = (e1-s1+1) + (e2-s2+1);
                        if(len>=largest){
                            first_s = s1;
                            first_e = e1;
                            second_s = s2;
                            second_e = e2;
                            largest = len;
                        } 
                    }
                }
            }
        }
    }
    for(int i=first_s;i<=first_e;i++)
        printf("%d ",arr[i]);
    for(int i=second_s;i<second_e;i++)
        printf("%d ",arr[i]);
    printf("%d", arr[second_e]); // without space
    // debug
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         if(check_pali(i,j,arr))
    //             dump_array(i,j,arr);
    //     }
    // }
    return 0;
}