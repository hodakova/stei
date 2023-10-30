// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月08日
// Topik     : Praktikum 1
// Deskripsi : Program mencari bilangan terbesar diantar tiga input angka

#include <stdio.h>

int terbesar(int a,int b,int c) {
    int maxx;
    if(a>b && a>c) maxx=a;
    else if(b>a && b>c) maxx=b;
    else maxx=c;
    return maxx;
}

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("Diantara %d, %d, dan %d. Angka terbesar adalah %d\n",a,b,c,terbesar(a,b,c));
    return 0;
}