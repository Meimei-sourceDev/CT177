#ifndef PLISTLIB_H
#define PLISTLIB_H

// ... all your typedefs and function prototypes here ...

typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node* Next;
};

typedef struct Node* List;
typedef List Position;

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