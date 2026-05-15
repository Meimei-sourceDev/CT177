#include <stdio.h>

#define MaxLength 100
typedef int ElementType;

typedef struct {
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

void makenullQueue(Queue *pQ) {
    pQ->Front = -1;
    pQ->Rear = -1;
}

int emptyQueue(Queue Q) {
    return Q.Front == -1;
}

int fullQueue(Queue Q) {
    return (Q.Rear - Q.Front + 1) == MaxLength;
}

void enQueue(ElementType x, Queue *Q) {
    if ((Q->Rear + 1) % MaxLength == Q->Front) {
        printf("Error: Queue full\n");
        return;
    }
    if (Q->Front == -1) Q->Front = 0; // First element case
    Q->Rear = (Q->Rear + 1) % MaxLength;
    Q->Elements[Q->Rear] = x;
}

void deQueue(Queue *pQ) {
    if (!emptyQueue(*pQ)) {
        if (pQ->Front == pQ->Rear) // If it was the last element
            makenullQueue(pQ);
        else
            pQ->Front++;
    }
}
ElementType front(Queue Q) {
    return Q.Elements[Q.Front];
}

int main() {
    Queue Q1, Q2;
    makenullQueue(&Q1);
    makenullQueue(&Q2);

    // Hardcoded Test Case
    // Example: n = 3
    // Q1 (Calling order): 3 1 2
    // Q2 (Ideal order):   1 3 2
    int initial_order[] = {3, 1, 2};
    int ideal_order[] = {1, 3, 2};
    int n = 3;

    for (int i = 0; i < n; i++) enQueue(initial_order[i], &Q1);
    for (int i = 0; i < n; i++) enQueue(ideal_order[i], &Q2);

    int time = 0;
    while (!emptyQueue(Q1)) {
        time++;
        if (front(Q1) == front(Q2)) {
            deQueue(&Q1);
            deQueue(&Q2);
        } else {
            ElementType temp = front(Q1);
            deQueue(&Q1);
            enQueue(temp, &Q1);
        }
    }

    printf("Total time taken: %d\n", time);
    // For the example above, result should be 5
    
    return 0;
}
