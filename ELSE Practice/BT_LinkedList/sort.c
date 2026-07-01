#include <stdio.h>
#include <stdlib.h>
#include "PListLib.c"

void nhap(List *L){
    makenullList(L);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        ElementType x; scanf("%d", &x);
        insertList(x, endList(*L), L);
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

void sort(List *L){
    Position P = *L;
    while(P->Next != NULL){
        Position Q = P->Next;
        while(Q->Next != NULL){
            if(Q->Next->Element < P->Next->Element){
                ElementType temp = Q->Next->Element;
                Q->Next->Element = P->Next->Element;
                P->Next->Element = temp;
            }
            Q = Q->Next;
        }
        P = P->Next;
    }
}

int main(){
    List L;
    nhap(&L);
    in(L);
    sort(&L);
    in(L);
}