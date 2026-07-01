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

//Only copy this function;
DaThuc khoitao(){
    DaThuc D = (DaThuc)malloc(sizeof(struct Node));
    D->Next = NULL;
    return D;
}

