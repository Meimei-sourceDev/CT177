#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char HoTen[50];
    char MSSV[10];
    float LT, TH1, TH2;
}SinhVien;

typedef struct{
    SinhVien A[100];
    int SoLuong;
}DanhSach;

void makenullList(DanhSach *L){
    L->SoLuong = 0;
}

int endList(DanhSach L){
    return L.SoLuong + 1;
}

int first(DanhSach L){
    return 1;
}

void append(SinhVien x, DanhSach *L){
    L->A[L->SoLuong] = x;
    L->SoLuong++;
}

int next(int i, DanhSach L){
    return i + 1;
}
SinhVien retrieve(int i, DanhSach L){
    return L.A[i - 1];
}

int find(char str[], DanhSach L){
    int i = first(L);
    while(i != endList(L)){
        if(strcmp(L.A[i - 1].MSSV, str) == 0){
            return i;
        }
        i = next(i, L);
    }
    return endList(L);
}

DanhSach readList(){
    DanhSach L;
    makenullList(&L);
    int n;
    if(scanf("%d", &n) != 1) return L;
    getchar();

    for(int i = 0; i < n; i++){
        SinhVien x;

        fgets(x.MSSV, 10, stdin);
        x.MSSV[strcspn(x.MSSV, "\n")] = '\0';

        fgets(x.HoTen, 50, stdin);
        x.HoTen[strcspn(x.HoTen, "\n")] = '\0';

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

void displayStudents(DanhSach L){
    int i = first(L);
    while(i != endList(L)){
        printf("%s - %s - %.2f - %.2f - %.2f\n", 
               L.A[i - 1].HoTen, L.A[i - 1].MSSV, L.A[i - 1].LT, L.A[i - 1].TH1, L.A[i - 1].TH2);
        i = next(i, L);
    }
}

void failClass(DanhSach L1, DanhSach *L2){
    makenullList(L2);
    int i = first(L1);
    while(i != endList(L1)){
        if((L1.A[i - 1].LT + L1.A[i - 1].TH1 + L1.A[i - 1].TH2) < 4.0){
            append(L1.A[i - 1], L2);
        }
        i = next(i, L1);
    }
}
int main() {
    // 1. Initialize and Read
    // Input format:
    // n (number of students)
    // MSSV
    // Name
    // LT TH1 TH2
    DanhSach mainList = readList();
    
    // 2. Prepare the Fail List
    DanhSach failedStudents;
    failClass(mainList, &failedStudents);
    
    // 3. Verify results
    // Instead of printing, we store the count.
    // You can set a breakpoint here in your IDE to inspect the lists.
    int totalCount = mainList.SoLuong;
    int failCount = failedStudents.SoLuong;

    // Returns the number of failed students as the exit status
    return failCount; 
    /*
    4
B2001
Nguyen Van A
1.0 1.0 1.0
B2002
Tran Thi B
4.0 4.0 4.0
B2001
Duplicate User
5.0 5.0 5.0
B2003
Le Van C
0.5 1.0 0.5*/
}