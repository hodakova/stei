// NIM             : 18222082
// Nama            : Ahmad Habibie Marjan
// Tanggal         : 23年10月06日
// Topik praktikum : Prapraktikum 5
// Deskripsi       : Menggunakan mesinkarakter.h

#include "mesinkarakter.h"

int main() {
    char x;
    scanf("%c",&x);
    START();
    char vokal[5] = {'a','i','u','e','o'};
    int count = 0;
    while(!IsEOP()) {
        if(GetCC()!=x && (GetCC()==vokal[0] || GetCC()==vokal[1] || GetCC()==vokal[2] || GetCC()==vokal[3] || GetCC()==vokal[4])) {
            count++;
            printf("%c",GetCC());
        }
        ADV();
    }
    if(count!=0) printf(" ");
    printf("%d\n",count);
}