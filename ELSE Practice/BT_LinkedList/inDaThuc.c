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

void inDaThuc(DaThuc D){
    Position P = D;
    int flag = 1;

    while(P->Next != NULL){
        if (P->Next->e.he_so != 0) {
            if (!flag) printf(P->Next->e.he_so > 0 ? " + " : " - ");
            else if (P->Next->e.he_so < 0) printf("-"); 
            double abs_hs = P->Next->e.he_so < 0 ? -P->Next->e.he_so : P->Next->e.he_so;
            printf("%.3fX^%d", abs_hs, P->Next->e.bac);
            flag = 0;
        }
        P = P->Next;
    }
    printf("\n");
}

int main(){

DaThuc d = khoitao();
DonThuc s1 = {-6.2, 4};
DonThuc s2 = {4.2, 0};
DonThuc s3 = {2, 4};
DonThuc s4 = {1, 9};
chenDonThuc(s1, &d);
chenDonThuc(s2, &d);
chenDonThuc(s3, &d);
chenDonThuc(s4, &d);
inDaThuc(d);	

return 0;
}
