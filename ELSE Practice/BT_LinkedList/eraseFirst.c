#include <stdio.h>
#include <stdlib.h>
#include "PListLib.c"

int member(ElementType x, List L){
    Position P = locate(x, L);
    return (P != NULL && P->Next != NULL) ? 1 : 0;
}

void addFirst(ElementType x, List *L){
    Position newNode = (Position)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = (*L)->Next;
    (*L)->Next =newNode;
}

void nhap(List *L){
    makenullList(L);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        ElementType x; scanf("%d", &x);
        if(!member(x, *L))
        addFirst(x, L);
    }
}

void in(List L){
    Position P = L;
    while(P->Next != NULL){
        printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}

void normalize(List *L){
    Position P = *L;
    while(P->Next != NULL){
        Position Q = P->Next;
        while(Q->Next != NULL){
            if(Q->Next->Element == P->Next->Element){
                deleteList(Q, L);
            }
            else Q = Q->Next;
        }
        P = P->Next;
    }
}

void intersection(List L1, List L2, List *L){
    makenullList(L);
    Position P = L1;
    while(P->Next != NULL){
        ElementType value = P->Next->Element;
        if(member(value, L2)){
            insertList(value, endList(*L), L);
        }
        P = P->Next;
    }
}

int main(){
    List L1, L2, L;
    nhap(&L1);
    nhap(&L2);
    in(L1);
    in(L2);
    intersection(L1, L2, &L);
    in(L);
}
