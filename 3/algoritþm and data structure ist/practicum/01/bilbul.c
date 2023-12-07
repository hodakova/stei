// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月07日
// Topik     : Prapraktikum 1
// Deskripsi : Program menerima input n bilangan bulat positif dan menampilkan output n baris dengan ketentuan

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int i = 1;
    for (i; i<=n; i++)
    {
        if (i%5==0) printf("Ril");
        if (i%3==0) printf("Nyata");
        if (i%3!=0 && i%5!=0) printf("%d", i);
        printf("\n");
    }

    return 0;
}