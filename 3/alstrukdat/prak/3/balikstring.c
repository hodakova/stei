// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月22日
// Topik     : Prapraktikum 3
// Deskripsi : Program implementasi balikstring.h

#include "balikstring.h"
#include <stdio.h>

int panjangString(char*x) {
    int i=0;
    while(*(x+i)!='\0') i++;
    return i;
}

void membalikString(char*str) {
    int i,n=panjangString(str);
    char tmp[n];
    for(i=0;i<n;i++) tmp[i]=*(str+i);
    for(i=0;i<n;i++) *(str+i)=tmp[n-i-1];
}