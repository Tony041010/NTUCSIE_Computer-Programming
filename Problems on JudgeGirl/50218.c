#include<stdlib.h>
//#include "treeToList.h"

struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
};
 
struct list {
    struct treenode *head;
    struct treenode *tail;
};
 
typedef struct treenode TreeNode;
typedef struct list List;

List rootList(TreeNode *root)
{
    List list;
    list.head = root;
    list.tail = root;
    list.head->right = NULL;
    list.tail->right = NULL;
    return list;
}

List merge(List a, List b)
{
    if(a.head == NULL){
        return b;
    }
    if(b.head == NULL){
        return a;
    }

    List c;
    c.head = a.head;
    a.tail->left = b.head; /* merge here */
    c.tail = b.tail;
    return c;

}

List treeToListFunc(TreeNode *root)
{
    if(root == NULL){
        List none = {NULL, NULL};
        return none;
    }

    List left = treeToListFunc(root->left);
    List right = treeToListFunc(root->right);

    if(root->value % 2 == 0){
        return merge(rootList(root), merge(left, right));
    }
    else{
        return merge(rootList(root), merge(right, left));
    }
}