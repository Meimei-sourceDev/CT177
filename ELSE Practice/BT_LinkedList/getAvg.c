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

float getAvg(List L){
    if(L->Next == NULL) return -10000.0f;
    int count = 0;
    int sum = 0;
    Position P = L;
    while(P ->Next != NULL){
        sum+= P->Next->Element;
        count++;
        P = P->Next;
    }
    return (float)sum / count;
}
int main(){
    List L;
    nhap(&L);
    in(L);
    printf("%.3f", getAvg(L));
}