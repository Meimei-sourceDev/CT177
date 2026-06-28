#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node* Next;
};

typedef struct Node* List;
typedef List Position;

void makenullList(List *L){
    (*L) = (struct Node*)malloc(sizeof(struct Node));
    (*L)->Next = NULL;
}

int emptyList(List L){
    return L->Next == NULL;
}

Position first(List L){
    return L->Next;
}

Position endList(List L){
    Position P = L;
    while(P->Next != NULL){
        P = P->Next;
    }
    return P;
}

Position next(Position P, List L){
    if(P == NULL) return P;
    return P->Next;
}

ElementType retrieve(Position P, List L){
    return P->Next->Element;
}

Position locate(ElementType x, List L){
    Position P = L;
    while(P->Next != NULL){
        if(P->Next->Element == x) 
            return P;
        P = P->Next;
    }
    return P;
}

void insertList(ElementType x, Position P, List *L){
    Position newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = P->Next;
    P->Next = newNode;
}

void deleteList(Position P, List *L){
    Position temp = P->Next;
    P->Next = temp->Next;
    free(temp);
}