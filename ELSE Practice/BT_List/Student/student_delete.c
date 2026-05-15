#include <string.h>
#include <stdio.h>
#define MAXL 40
typedef struct{
    char HoTen[50];
    char MSSV[10];
    float LT, TH1, TH2;
}SinhVien;

typedef struct{
    SinhVien sv[MAXL];
    int n;
}List;

typedef int Position;

Position first(List L){
    return 1;
}
Position endList(List L){
    return L.n + 1;
}
Position next(int P, List L){
    return P + 1;
}
void makenullList(List *L){
    L->n = 0;
}
Position find(char str[], List L){
    Position P = first(L);
    while(P != endList(L)){
        if(strcmp(L.sv[P - 1].MSSV, str) == 0){
            return P;
        }
        P = next(P, L);
    }
    return L.n + 1;
}
void append(SinhVien x, List *L){
    L->sv[L->n] = x;
    L->n++;
}
List readList(){
    List L;
    int n;
    makenullList(&L);
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        SinhVien x;
        printf("\nname: ");
        fgets(x.HoTen, 50, stdin);
        x.HoTen[strcspn(x.HoTen, "\n")] = '\0';
        printf("\nID: ");
        fgets(x.MSSV, 10, stdin);
        x.MSSV[strcspn(x.MSSV, "\n")] = '\0';
        printf("\nAcademics: ");
        scanf("%f%f%f", &x.LT, &x.TH1, &x.TH2);
        getchar();

        if(find(x.MSSV, L) == endList(L)){
            append(x, &L);
        }else{
            printf("MSSV da ton tai\n");
        }
    }
    return L;
}
void printList(List L){
    Position P = first(L);
    while (P != endList(L)){
        printf("%s - %s - %2f - %2f - %2f\n", L.sv[P - 1].HoTen, L.sv[P - 1].MSSV, L.sv[P - 1].LT, L.sv[P - 1].TH1, L.sv[P - 1].TH2);
        P = next(P, L);
    }
}

void deleteStudent(char mssv[10], List *L){
    Position P = find(mssv, *L);
    if(P != endList(*L)){
        printf("Tim thay sinh vien, status: ");
        printf("%s - %s - %2f - %2f - %2f\n", L->sv[P - 1].HoTen, L->sv[P - 1].MSSV, L->sv[P - 1].LT, L->sv[P - 1].TH1, L->sv[P - 1].TH2);
        Position Q;
        for(Q = P - 1; Q < L->n - 1; Q++){
            L->sv[Q] = L->sv[Q + 1];
        }
        L->n--;
    }else{
        printf("Sinh vien khong ton tai\n");
    }
}
int main(){
    List sv = readList();
    
    // Read the MSSV to delete
    printf("Enter ID to delete: ");
    char s[10];
    fgets(s, 10, stdin);
    s[strcspn(s, "\n")] = '\0'; // Cleaner way to remove newline
    
    printf("\n--- Original List ---\n");
    printList(sv);
    
    printf("\n--- Deleting Student %s ---\n", s);
    deleteStudent(s, &sv);
    
    printf("\n--- Updated List ---\n");
    printList(sv);
    
    return 0;
}