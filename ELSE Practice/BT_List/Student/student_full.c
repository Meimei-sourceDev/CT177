#include <string.h>
#include <stdio.h>

struct SinhVien{
  char MSSV[10];
  char HoTen[50];
  float DiemLT, DiemTH1, DiemTH2;
};
typedef struct SinhVien ElementType;
typedef int Position;

typedef struct{
    ElementType A[40];
    Position n;
}DanhSach;

void append(ElementType data, DanhSach *L){
    L->A[L->n] = data;
    L->n++;
}

DanhSach nhapSV(){
    DanhSach L;
    L.n = 0;
    int n; 
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        ElementType sv;
        fgets(sv.MSSV, 10, stdin);
        sv.MSSV[strcspn(sv.MSSV, "\n")] = '\0';
        
        fgets(sv.HoTen, 50, stdin);
        sv.HoTen[strcspn(sv.HoTen, "\n")] = '\0';
        
        scanf("%f%f%f", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);
        getchar();
        append(sv, &L);
    }
    return L;
}

void inSV(DanhSach L){
    if(L.n == 0) return;
    Position P = 1;
    while(P != L.n + 1){
        ElementType sv = L.A[P - 1];
        printf("%s - %s - %.2f - %.2f - %.2f\n", sv.MSSV, sv.HoTen, sv.DiemLT, sv.DiemTH1, sv.DiemTH2);
        P = P + 1;
    }
}

int dat(ElementType sv, DanhSach L){
    float res = sv.DiemLT + sv.DiemTH1 + sv.DiemTH2;
    return res >= 4;
}

void khongDat(DanhSach L1, DanhSach *L2){
    L2->n = 0;
    Position P = 1;
    while(P != L1.n + 1){
        ElementType sv = L1.A[P - 1];
        if(!dat(sv, L1)){
            append(sv, L2);
        }
        P = P + 1;
    }
}

int main(){
    DanhSach L = nhapSV();
    inSV(L);
    printf("Sinh vien KHONG DAT\n");
    DanhSach L1;
    khongDat(L, &L1);
    inSV(L1);
    return 0;
}