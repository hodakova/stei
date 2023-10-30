// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月08日
// Topik     : Praktikum 1
// Deskripsi : Program yang dapat menentukan apakah suatu bilangan merupakan bilangan cantik atau tidak

#include <stdio.h>

int isCantik(int a, int b) {
    return (a+b)%4==0 || (a*b)%4==0;
}

int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    if(isCantik(a,b)) printf("Y\n");
    else printf("N\n");
    return 0;
}