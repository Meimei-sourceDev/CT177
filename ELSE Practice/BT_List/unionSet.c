#include <stdio.h>
#include "AListLib.h"

void normalize(List *L){
    Position i,j, writeIndex = 0;
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

int member(ElementType x, List L){
    Position P = first(L);
    while(P != endList(L)){
        if(retrieve(P, L) == x){
            return 1;
        }
        P = next(P, L);
    }
    return 0;
}

List unionSet(List A, List B){
    List C;
    makenullList(&C);
    for(int i = 1; i <= A.Last; i++){
        insertList(retrieve(i, A), endList(C), &C);
    }
    for(int j = 1; j <= B.Last; j++){
        int item = retrieve(j, B);
        if(!member(item, C)){
            insertList(item, endList(C), &C);
        }
    }
    return C;
}

int main(){
}