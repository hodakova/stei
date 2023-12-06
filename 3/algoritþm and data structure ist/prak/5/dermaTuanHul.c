// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月06日
// Topik     : Praktikum 5
// Deskripsi : Program realisasi derma untuk Tuan Hul

#include "mesinkata.h"
#include <stdio.h>

int main() {
    int r = 0;
    STARTWORD();
    r += currentWord.Length;
    while(!isEndWord())
        ADVWORD();
    r += currentWord.Length;
    printf("%d\n", r);
    return 0;
}