// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月12日
// Topik     : Prapraktikum 2
// Deskripsi : Program untuk menghitung banyak kata

#include <stdio.h>

int main() {
    char kalimah[100];
    int i, count=1;
    scanf("%[^\n]kalimah", &kalimah);
    for (i=0; kalimah[i]!='\0'; i++)
        if (kalimah[i]==' ' && kalimah[i+1]!=' ') count++;
    printf("%d\n", count);
    return 0;
}