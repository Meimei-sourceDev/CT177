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
/*
void removeAll(ElementType x, List *L){
    Position P = *L;
    while(P->Next != NULL){
        if(P->Next->Element == x){
            deleteList(P, L);
        }
        else P = P->Next;
    }
}
*/

void removeAll(ElementType x, List *L){
    Position P = locate(x, *L);
    while(P != NULL && P->Next != NULL){
        deleteList(P, L);
        P = locate(x, *L);
    }
}

int main(){
    List L;
    nhap(&L);
    in(L);

    int n; scanf("%d", &n);
    removeAll(n, &L);

    in(L);
}