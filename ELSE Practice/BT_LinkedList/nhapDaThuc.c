#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double he_so;
  int bac;
} DonThuc;

struct Node{
     DonThuc e;    
     struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;


DaThuc khoitao(){
    DaThuc D = (DaThuc)malloc(sizeof(struct Node));
    D->Next = NULL;
    return D;
}

void chenDonThuc(DonThuc x, DaThuc *D){
    Position P = *D;
    while(P->Next != NULL && P->Next->e.bac > x.bac){
        P = P->Next;
    }

    if(P->Next != NULL && P->Next->e.bac == x.bac){
        P->Next->e.he_so += x.he_so;
    }
    else{
        Position temp = (Position)malloc(sizeof(struct Node));
        temp->e = x;
        temp->Next = P->Next;
        P->Next = temp;
    }
}

//only copy the following function;

DaThuc nhapDaThuc(){
    DaThuc D;
    D = khoitao();

    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        DonThuc e;
        scanf("%lf", &e.he_so);
        scanf("%d", &e.bac);
        chenDonThuc(e, &D);
    }
    return D;
}


