#include <stdio.h>
#define MaxLength 100
typedef int ElementType;
typedef int Position;

typedef struct{
    ElementType Element[MaxLength];
    Position Last;
}List;

void makenullList(List *L){
    L->Last = 0;
}
Position first(List L){
    return 1;
}
Position endList(List L){
    return L.Last + 1;
}
int emptyList(List L){
    return (L.Last == 0);
}
Position next(Position P, List L){
    if(P < 1 || P > L.Last + 1) return -1;
    return P + 1;
}
ElementType retrieve(Position P, List L){
    if(P < 1 || P > L.Last + 1) return -1;
    return L.Element[P - 1];
}
Position locate(ElementType element, List L){
    Position P = first(L);
    while(P != endList(L)){
        if(retrieve(P, L) == element) return P;
        P = next(P, L);
    }
    return endList(L);
}
void printList(List L){
    Position P = first(L);
    while(P != endList(L)){
        printf("%d ", retrieve(P, L));
        P = next(P, L);
    }
    printf("\n");
}
void sort(List *L){
    Position P, Q;
    ElementType temp;
    for(P = 0; P < L->Last; P++){
        for(Q = 0; Q < L->Last - P - 1; Q++){
            if(L->Element[Q] > L->Element[Q + 1]){
                temp = L->Element[Q];
                L->Element[Q] = L->Element[Q + 1];
                L->Element[Q + 1] = temp;
            }
        }
    }
}
void normalize(List *L){
    if(L->Last == 0) return;
    Position i,j, writeIndex = 0;
    for(i = 0; i < L->Last; i++){
        int flag = 0;
        for(j = 0; j < writeIndex; j++){
            if(L->Element[j] == L->Element[i]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            L->Element[writeIndex] = L->Element[i];
            writeIndex++;
        }
    }
    L->Last = writeIndex;
}
void insert(ElementType x, Position P, List *L){
    if(L->Last >= MaxLength) printf("List is full\n");
    else if(P < 1 || P > L->Last + 1) printf("Position invalid\n");
    else{
        Position Q;
        for(Q = L->Last; Q >= P; Q--){
            L->Element[Q] = L->Element[Q - 1];
        }
        L->Element[P - 1] = x;
        L->Last++;
    } 
}
void delete(Position P, List* L){
    if(P < 1 || P > L->Last) printf("invalid position");
    else{
        Position Q;
        for(Q = P - 1; Q < L->Last - 1; Q++){
            L->Element[Q] = L->Element[Q + 1];
        }
        L->Last--;
    }
}
void destroyList(ElementType x, List *L){
    while(locate(x, *L) != L->Last + 1){
        delete(locate(x, *L), L);
    }
}

void readList(List *L){
    int n;
    printf("Enter list size: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        printf("Enter element #: ");
        scanf("%d", &x);
        insert(x, endList(*L), L);
    }
    printf("\n");
}

int main(){
    List L;
    makenullList(&L);
    readList(&L);
    printList(L);
    normalize(&L);
    printList(L);
}