#include <stdio.h>
#include "AListLib.h"

void deleteList(Position P, List *L){
    if(P < 1 || P > L->Last) return;
    else{
        Position Q;
        for(Q = P - 1; Q < L->Last -1 ;Q++)
        L->Elements[Q] = L->Elements[Q + 1];
        L->Last--;
    }
}
void removeFirst(ElementType x, List *L){
    Position P = locate(x, *L);
    if(P != endList(*L)){
        deleteList(P, L);
    }
}