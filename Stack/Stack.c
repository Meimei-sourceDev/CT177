#include <stdio.h>

#define MAXL 100
typedef int ElementType;

typedef struct {
    ElementType DuLieu[MAXL];
    int Dinh; // Current top index
} NganXep;

// Initialize: Set Dinh to MAXL (Stack grows from right to left)
void khoitao(NganXep *pS) {
    pS->Dinh = MAXL
;
}

// Check if Empty: Top is back at the starting position
int ktRong(NganXep S) {
    return S.Dinh == MAXL
;
}

// Check if Full: Top has reached the first index
int ktDay(NganXep S) {
    return S.Dinh == 0;
}

// Push: Decrement Dinh then insert
void them(int x, NganXep *pS) {
    if (!ktDay(*pS)) {
        pS->Dinh--;
        pS->DuLieu[pS->Dinh] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop: Simply increment Dinh
void xoa(NganXep *pS) {
    if (!ktRong(*pS)) {
        pS->Dinh++;
    } else {
        printf("Stack Underflow\n");
    }
}

// Top Value
int giatriDinh(NganXep S) {
    if (!ktRong(S)) {
        return S.DuLieu[S.Dinh];
    }
    return -1; // Error value
}

// Display: Print without destroying the stack
void hienthi(NganXep S) {
    int i;
    for (i = S.Dinh; i < MAXL
	; i++) {
        printf("%d ", S.DuLieu[i]);
    }
    printf("\n");
}