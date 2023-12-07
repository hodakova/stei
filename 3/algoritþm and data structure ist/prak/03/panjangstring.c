// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月19日
// Topik     : Prapraktikum 3
// Deskripsi : Program implementasi panjangstring.h

#include "panjangstring.h"

int panjangString(char*x) {
    int i=0;
    while(*(x+i)!='\0') i++;
    return i;
}