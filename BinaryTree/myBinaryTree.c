#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef int ElementType;

typedef struct Node{
    DataType Data;
    struct Node* Left;
    struct Node* Right;
}Node;
typedef struct Node* Tree;

int findIndex(int value, char in[], int start, int end){
    for(int i = start; i <= end; i++){
        if(in[i] == value) return i;
    }
    return -1;
}

void makenullTree(Tree *root) {
    *root = NULL;
}

int emptyTree(Tree T){
    return (T == NULL);
}

Tree leftChild(Tree n){
    if(n != NULL) return n->Left;
    return NULL;
}
Tree rightChild(Tree n){
    if(n != NULL) return n->Right;
    return NULL;
}

int isLeaf(Tree n){
    if(n != NULL) return (n->Left == NULL && n->Right == NULL);
}
void preOrder(Tree T);
void inOrder(Tree T);
void postOrder(Tree T);
Tree createTree(ElementType data);