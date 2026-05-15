#include <stdio.h>
#include "AListLib.h"

void printOdd(List L){
    Position P = first(L);
    while(P != endList(L)){
        if(retrieve(P, L) & 1){
            printf("%d ", retrieve(P, L));
        }
        P = next(P, L);
    }
    printf("\n");
}
void copyEven(List L1, List *L2){
    makenullList(L2);
    Position P = first(L1);
    while(P != endList(L1)){
        ElementType value = retrieve(P, L1);
        if(!(value & 1)) insertList(value, endList(*L2), L2);
        P = next(P, L1);
    }
    printf("\n");
}

int main(){
}