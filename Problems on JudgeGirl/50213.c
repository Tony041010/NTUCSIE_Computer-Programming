#include<stdio.h>
#define MAXN 100000

void printArray(int array[], int num){
    for(int i = 0 ; i < num ; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

void mergeSort(int numbers[], int num)
{
    printArray(numbers, num);

    if(num <= 1){
        return;
    }
    int leftLength = num / 2;
    int rightLength = num - leftLength;
    int left[leftLength];
    int right[rightLength];
    for(int i = 0 ; i < leftLength ; i++){
        left[i] = numbers[i];
    }
    for(int i = 0 ; i < rightLength ; i++){
        right[i] = numbers[leftLength + i];
    }

    mergeSort(left, leftLength);
    mergeSort(right, rightLength);

    int index = 0;
    int leftIndex = 0, rightIndex = 0;
    while(!(leftIndex == leftLength && rightIndex == rightLength)){
        if(rightIndex == rightLength || (leftIndex < leftLength && left[leftIndex] < right[rightIndex])){
            numbers[index++] = left[leftIndex++];
        }
        else{
            numbers[index++] = right[rightIndex++];
        }
    }

    printArray(numbers, num);
    return;
}

int main()
{
    int numbers[MAXN];
    int index = 0;
    while(scanf("%d", &numbers[index]) != EOF){
        index++;
    }

    mergeSort(numbers, index);

    return 0;
}