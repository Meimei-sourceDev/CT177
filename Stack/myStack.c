#include <stdio.h>

#define MAXL 100
typedef int ElementType;

typedef struct{
    ElementType Data[MAXL];
    int Top;
}Stack;

void newStack(Stack *stack){
    stack->Top = MAXL;
}
int isEmpty(Stack *stack){
    return stack->Top == MAXL;
}
int isFull(Stack *stack){
    return stack->Top == 0;
}
void push(ElementType data, Stack *stack){
    if(!isFull(stack)){
        stack->Top--;
        stack->Data[stack->Top] = data;
    } else printf("Stack overflow\n");
}
void pop(Stack *stack){
    if(!isEmpty(stack)){
        stack->Top++;
    }else printf("Stack underflow\n");
}
int retrieveTop(Stack *stack){
    if(!isEmpty(stack)){
        return stack->Data[stack->Top];
    }
    return -1;
}
void printStack(Stack *stack){
    for(int i = stack->Top; i < MAXL; i++){
        printf("%d ", stack->Data[i]);
    }
    printf("\n");
}
int main() {
    Stack s;
    newStack(&s);

    printf("--- Testing Push and Print ---\n");
    push(10, &s);
    push(20, &s);
    push(30, &s);
    printf("Stack (should be 30 20 10): ");
    printStack(&s);

    printf("\n--- Testing Top and Pop ---\n");
    printf("Top element is: %d\n", retrieveTop(&s));
    
    pop(&s);
    printf("After one pop (should be 20 10): ");
    printStack(&s);

    printf("\n--- Testing Emptying the Stack ---\n");
    pop(&s);
    pop(&s);
    printf("Is stack empty? %s\n", isEmpty(&s) ? "Yes" : "No");
    
    // Testing Underflow
    printf("Trying to pop an empty stack: ");
    pop(&s); 

    printf("\n--- Testing Overflow ---\n");
    newStack(&s); // Reset
    printf("Filling stack to the limit...\n");
    for(int i = 0; i < MAXL; i++) {
        push(i + 1, &s);
    }
    printf("Attempting to push the 101st element: ");
    push(999, &s); // Should trigger overflow

    return 0;
}