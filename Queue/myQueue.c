#include <stdio.h>
#include <stdlib.h>
#define MAXL 100

typedef int ElementType;
typedef struct {
    ElementType Element[MAXL];
    int Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
    pQ->Front = -1;
    pQ->Rear = -1;
}
int emptyQueue(Queue Q){
    return Q.Front == -1;
}
int fullQueue(Queue Q){
    return (Q.Rear - Q.Front + 1) == MAXL;
}
ElementType front(Queue Q){
    if(!emptyQueue(Q))
        return Q.Element[Q.Front];
}
ElementType back(Queue Q){
    if(!emptyQueue(Q))
        return Q.Element[Q.Rear];
}
void enQueue(ElementType data, Queue *Q){
    if((Q->Rear + 1) % MAXL == Q->Front){
        printf("Queue is full\n");
        return;
    } 
    else{
        if(Q->Front == -1) Q->Front = 0;
        Q->Rear = (Q->Rear + 1) % MAXL;
        Q->Element[Q->Rear] = data;
    }
}
void deQueue(Queue *Q){
    if(emptyQueue(*Q)){
        printf("Queue underflow\n");
        return;
    }
    if(Q->Front == Q->Rear){
        Q->Front = -1;
        Q->Rear = -1;
    }
    else{
        Q->Front = (Q->Front + 1) % MAXL;
    }
}