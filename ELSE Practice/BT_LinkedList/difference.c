#include <stdio.h>
#include <stdlib.h>
#include "PListLib.c"

void normalize(List *L){
	Position P = *L;
	while(P->Next != NULL){
		Position Q = P->Next;
		while(Q->Next != NULL){
			if(Q->Next->Element == P->Next->Element){
				deleteList(Q, L);
			}
			else Q = Q->Next;
		}
		P = P->Next;
	}
}

int member(ElementType x, List L){
	Position P = L;
	while(P->Next != NULL){
		if(P->Next->Element == x) return 1;
		P = P->Next;
	}
	return 0;
}

void addFirst(ElementType x, List *L){
	Position newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->Element = x;
	newNode->Next = (*L)->Next;
	(*L)->Next = newNode;
}

List nhap(){
	List L;
	makenullList(&L);
	int n; scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		if(!member(x, L))
		addFirst(x, &L);
	}
	normalize(&L);
	return L;
}

void in(List L){
	Position P = L;
	while(P->Next != NULL){
		printf("%d ", P->Next->Element);
		P = P->Next;
	}
	printf("\n");
}

void difference(List L1, List L2, List *L){
	makenullList(L);
	Position P = L1;
	while(P->Next != NULL){
		int value = P->Next->Element;
		if(!member(value, L2)){ //nho check member
			insertList(value, endList(*L), L);
		}
		P = P->Next;
	}
}

int main(){
	List L1, L2, L;
	L1 = nhap();
	L2 = nhap();

	in(L1);
	in(L2);
	difference(L1, L2, &L);
	in(L);
}



