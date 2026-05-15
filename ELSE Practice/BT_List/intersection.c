#include <stdio.h>
#include "AListLib.h"

void normalize(List *L){
    Position i, j, writeIndex = 0;
    for(i = 0; i < L->Last; i++){
        int flag = 0;
        for(j = 0; j < writeIndex; j++){
            if(L->Elements[j] == L->Elements[i]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            L->Elements[writeIndex] = L->Elements[i];
            writeIndex++;
        }
    }
    L->Last = writeIndex;
}

List intersection(List A, List B){
    List C;
    makenullList(&C);
    Position P = first(A);
    while(P != endList(A)){
        Position Q = first(B);
        while(Q != endList(B)){
            if(retrieve(P, A) == retrieve(Q, B)){
                insertList(retrieve(P, A), endList(C), &C);
            }
            Q = next(Q, B);
        }
        P = next(P, A);
    }
    return C;
}//O(n*m);