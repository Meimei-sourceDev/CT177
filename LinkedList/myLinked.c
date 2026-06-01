#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; //an alias for int
typedef struct Node* NodeType; 

struct Node{//contains the data (element) and point to the next blocl (Next)
    ElementType Element;
    NodeType Next;
};
typedef NodeType Position; //refer to a pointer to a specific node during traversal
typedef Position List; //refer to head of the list

void makenullList(List *Header){ //make an empty list
    (*Header) = (struct Node*)malloc(sizeof(struct Node));
    if(*Header == NULL){
        printf("ERROR: Out of memory\n");
        return;
    }
    (*Header)->Next = NULL;
}

void readList(List *pL){
    int n;
    printf("Enter the size of the list: ");
    if(scanf("%d", &n)!=1) return;

    makenullList(pL);//make null list and assign it to pL;
    Position P = *pL;//create a temp pointer P, it point to the header (position NULL);

    for(int i = 0; i < n; i++){//each iteration is one link of the chain;
        ElementType x;
        printf("Enter element %d:", i + 1);
        if(scanf("%d", &x)!=1) break;

        Position newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == 0){
            printf("Memory allocation failed\n");
            return;
        }
        newNode->Element = x;//newNode.Element = x, we drop the user input into that new block that we created;
        newNode->Next = NULL;//we again assign NULL to that new block as if it is the end of the list
        P->Next = newNode;//IMPORTANT: it tells the current last node to points it "Next" arrow to the new node we just created
        P = P->Next;//We move the crawler P forward, P now points to the node we just added.
    }
}

void printList(List L){
    Position P = L->Next;//L is the header, same as P = Header;
    if(P == NULL){//safety check;
        return;
    }
    printf("List contains: ");
    while(P != NULL){
        printf("%d ", P->Element);//print the data;
        P = P->Next;//assigns the P to point the the next drawer;
    }
    printf("\n");
}

Position Locate(ElementType x, List L){
    Position P = L; //actually this is P = head;
    int found = 0;
    while(P->Next != NULL && found == 0){
        if(P->Next->Element == x) found = 1;//use the P to find if "Element x" is present at the "Next" house
        else P = P->Next; //if there's none, we tells the P to go to the "Next of next" house;
    }
    return P;//if x was found, P is the node before x; otherwise P will be the last node in the list;
}

void deleteList(Position P, List L){
    Position temp;
    if(P == NULL || P->Next == NULL){ // If P is the last node, there is nothing after it to delete
        return;
    }
    temp = P->Next;          // temp is the node we want to kill
    P->Next = temp->Next;    // P bypasses temp to point to the one after it
    free(temp);              // Free memory
}


void Erase(int x, List *pL){
    Position P = Locate(x, *pL);//locate the position of x in list;
    if(P->Next != NULL){
        deleteList(P, *pL);
    }
    else{
        printf("Not found %d\n", x);
    }
}

void bubbleSort(List *pL){
    Position P = *pL;
    while(P->Next != NULL){
        Position Q = P->Next;
        while(Q->Next != NULL){
            if(P->Next->Element > Q->Next->Element){
                int temp = P->Next->Element;
                P->Next->Element = Q->Next->Element;
                Q->Next->Element = temp;
            }
            Q = Q->Next;
        }
        P = P->Next;
    }//the above is the equivalent of i++ and j++ in array; but extras step lol;
}

float getAvg(List L){
    Position P = L;
    float sum = 0, count = 0;
    if(P->Next == NULL) return 0.0;
    while(P->Next!= NULL){
        sum += P->Next->Element;
        count++;
        P = P->Next;
    }
    return sum / count;
}

void InsertAt(ElementType x, Position P, List* pL){
    Position temp = (struct Node*)malloc(sizeof(struct Node));
    temp->Element = x;
    temp->Next = P->Next;
    P->Next = temp;
}

void addFirst(ElementType x, List L){
    Position P = L;
    Position temp = (struct Node*)malloc(sizeof(struct Node));
    temp->Element = x;
    temp->Next = P->Next;
    P->Next = temp;
}

int getMax(List L){
    Position P = L->Next;
    ElementType Max = P->Element;
    while(P != NULL){
        if(P->Element > Max){
            Max = P->Element;
        }
        P = P->Next;
    }
    return Max;
}

void removeAll(ElementType x, List *L){
    Position P = *L;
    while(P->Next != NULL){
        if(P->Next->Element == x){
            deleteList(P, *L);
        }else P = P->Next;
    }
}

void append(ElementType x, List *L){
    Position P = *L;
    while(P->Next != NULL){
        P = P->Next;
    }
    Position newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode ->Next = NULL;
    P->Next = newNode;
}

void printOddNumbers(List L){
    Position P = L;
    while(P->Next != NULL){
        if(P->Next->Element % 2){
            printf("%d ", P->Next->Element);
        }
        P = P->Next;
    }
    printf("\n");
}


void copyEvenNumbers(List L1, List *L2){
    Position P = L1;
    makenullList(L2);
    while(P->Next != NULL){
        if(P->Next->Element % 2 == 0){
            append(P->Next->Element, L2);
        }
        P = P->Next;
    }
}

int isMember(ElementType x, List L){
    return Locate(x, L)->Next != NULL;
}

List difference(List L1, List L2){
    List tempL;
    makenullList(&tempL);
    Position P = L1;
    while(P->Next != NULL){
        if(isMember(P->Next->Element, L2)){
            append(P->Next->Element, &tempL);
        }
        P = P->Next;
    }
    return tempL;
}

void destroyList(List *pL){
    Position P = *pL;
    Position temp;
    while(P != NULL){
        temp = P;
        P = P->Next;
        free(temp);
    }
    *pL = NULL;
}
void reverseList(List L){
    if(L->Next == NULL || L->Next->Next == NULL) return;
    Position prev = NULL;
    Position current = L->Next;
    Position nextNode = NULL;
    while(current != NULL){
        nextNode = current->Next;
        current->Next = prev;
        prev = current;
        current = nextNode;
    }
    L->Next = prev;
}
void normalize(List *L){
    Position P = *L;
    while(P->Next != NULL){
        Position Q = P->Next;
        while(Q->Next != NULL){
            if(Q->Next->Element == P->Next->Element){
                Position temp = Q->Next;
                Q->Next = temp->Next;
                free(temp);
            }
            else Q = Q->Next;
        }
        P = P->Next;
    }
}

int main() {
    List L;
    
    // 1. Initialize and Read
    readList(&L);
    printList(L);

    // 2. Test Append and Max
    printf("Appending 99...\n");
    append(99, &L);
    printList(L);
    printf("Max element: %d\n", getMax(L));

    // 3. Test Deletion
    int toDelete;
    printf("Enter a number to erase: ");
    scanf("%d", &toDelete);
    Erase(toDelete, &L);
    printList(L);

    // 4. Test Sorting
    printf("Sorting list...\n");
    bubbleSort(&L);
    printList(L);
    reverseList(L);
    printList(L);

    return 0;
}
