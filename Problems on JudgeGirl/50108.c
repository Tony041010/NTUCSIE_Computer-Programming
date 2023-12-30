#include<stdlib.h>
#include<stdint.h>
//#include""construct.h"

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}Node;

Node *genNode(int value, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

int compare(void *a, void *b)
{
    int *aptr = (int *)a;
    int *bptr = (int *)b;
    if(*aptr > *bptr){
        return -1;
    }
    else if(*aptr < *bptr){
        return 1;
    }
    else{
        return 0;
    }
}

int findkth(int seesaw[], int start, int end)
{
    int length = end - start + 1;
    if(length < MAXLENGTH){
        return -1; /* genList then */
    }

    int temp[16385];
    for(int i = 0 ; i < length ; i++){
        temp[i] = seesaw[i+start];
    }
    qsort(temp, length, sizeof(int), compare);

    for(int i = start ; i <= end ; i++){
        if(seesaw[i] == temp[MAXLENGTH - 1]){
            return i;
        }
    }
    return -1;
}

Node *genList(int seesaw[], int start, int end){
    if(end < start){
        return NULL;
    }
    else{
        return genNode(seesaw[end], genList(seesaw, start, end - 1), NULL);
    }
}

Node *genTree(int seesaw[], int start, int end){
    if(end < start){
        return NULL;
    }

    int kthIndex = findkth(seesaw, start, end);
    if(kthIndex == -1){
        return genList(seesaw, start, end);
    }
    else{
        return genNode(seesaw[kthIndex], genTree(seesaw, start, kthIndex-1), genTree(seesaw, kthIndex+1, end));
    }
}

Node *ConstructTree(int seesaw[], int N){
    return genTree(seesaw, 0, N-1);
}