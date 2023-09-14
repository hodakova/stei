// NIM             : 18222082
// Nama            : Ahmad Habibie Marjan
// Tanggal         : 14-09-23
// Topik praktikum : Praktikum 2 2022
// Deskripsi       : Membandingkan apakah kedua kata sama atau tidak

#include <stdio.h>

int main() {
    int cheque=1, i;
    char kata1[100], kata2[100];
    scanf("%s", kata1);
    scanf("%s", kata2);
    for (i=0; kata1[i]!='\0' || kata2[i]!='\0'; i++) {
        if (kata1[i] != kata2[i]) {
            cheque=0;
            break;
        }
    }
    printf("%d\n", cheque);
    return 0;
}