#include <stdlib.h>
#include <stdio.h>
#include "PListLib.c"

int member(ElementType x, List L){
    Position P = locate(x, L);
    if(P != NULL) return 1;
    return 0;
}

void normallize(List *L){
    Position P = *L;
    while(P->Next != NULL){
        Position Q = P->Next;
        while(Q->Next != NULL){
            if(Q->Next->Element == P->Next->Element){
                deleteList(P, L);
            }
            else Q = Q->Next;
        }
        P = P->Next;
    }
}

void addFirst(ElementType x, List *L){
    Position newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = (*L)->Next;
    (*L)->Next = newNode;
}

List nhap(){
    List L;
    makenullList(&L);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        ElementType x; scanf("%d", &x);
        if(!member(x, L))
        addFirst(x, &L);
    }
    normallize(&L);
    return L;
}

void in(List L){
    Position P = L;
    while(P->Next != NULL){
        printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}

void unionSet(List L1, List L2, List *L){
    Position P = L1;
    while(P->Next != NULL){
        int value = retrieve(P, L1);
        if(!member(value, L2)){
            insertList(value, endList(L), L);
        }
        P = P->Next;
    }
}

int main(){
    List L1, L2, L;
    L1 = nhap();
    L2 = nhap();
    unionSet(L1, L2, &L);

    in(L1);
    in(L2);
    in(L);
}



