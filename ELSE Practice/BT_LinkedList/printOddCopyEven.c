#include <stdlib.h>
#include <stdio.h>
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

void printOdd(List L){
    Position P = L;
    while(P->Next != NULL){
        int value = P->Next->Element;
        if((value & 1) != 0){
            printf("%d ", value);
        }
        P = P->Next;
    }
    printf("\n");
}

void copyEven(List L1, List *L){
    makenullList(L);
    Position P = L1;
    while(P->Next != NULL){
        int value = P->Next->Element;
        if((value & 1) == 0){
            insertList(value, endList(*L), L);
        }
        P = P->Next;
    }
}
int main(){
    List L1, L2;
    nhap(&L1);
    in(L1);
    printOdd(L1);
    copyEven(L1, &L2);
    in(L2);
}