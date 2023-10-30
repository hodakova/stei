// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月15日
// Topik     : Prapraktikum 2
// Deskripsi : Program menentukan banyak angka yang memiliki jumlah digit genap

#include <stdio.h>

int main() {
    int n, a, i, count=0, countdigit;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &a);
        countdigit=0;
        while (a>0) {
            a/=10;
            countdigit++;
        }
        if (countdigit%2==0) count++;
    }
    printf("%d\n", count);
    return 0;
}