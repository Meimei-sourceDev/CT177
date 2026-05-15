#include <stdlib.h>
#include <stdio.h>

typedef char DataType;
typedef struct Node{
    DataType Data;
    struct Node *Left, *Right;
}Node;

typedef Node* Tree;