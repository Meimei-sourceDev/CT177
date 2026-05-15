#ifndef ALISTLIB_H
#define ALISTLIB_H

// ... all your typedefs and function prototypes here ...


#define MaxLength 100

typedef int ElementType;
typedef int Position; 
typedef struct {
    ElementType Elements[MaxLength];
    Position Last;
} List; 

void makenullList(List *L);
int emptyList(List L);
ElementType retrieve(Position P, List L);
Position first(List L);
Position endList(List L);
Position next(Position P, List L);
Position locate(ElementType X, List L);
void insertList(ElementType X, Position P, List *L);
void deleteList(Position P, List *L);
void printList(List L);

#endif