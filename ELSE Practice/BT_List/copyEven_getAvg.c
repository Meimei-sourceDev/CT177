#include <stdio.h>
#include "AListLib.h"

void copyEven(List *L2, List L1){
    Position P = first(L1);
    makenullList(L2);
    while(P != endList(L1)){
        ElementType value = L1.Elements[P - 1];
        if(!(value & 1)){
            insertList(value, endList(*L2), L2);
        }
        P = next(P, L1);
    }
    printf("\n");
}

float getAvgEven(List L){
    if(L.Last <= 0) return 1e-6f;
    int sum = 0;
    int count = 0;
    Position P = first(L);
    while(P != endList(L)){
        ElementType value = L.Elements[P - 1];
        if(!(value & 1)){
            sum += value;
            count++;
        }
        P = next(P, L);
    }
    if(count == 0) return 1e-6f;
    return sum / (float)count;
}

int main(){
}