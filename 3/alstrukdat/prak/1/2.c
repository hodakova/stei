// NIM_Nama  : 18222082_Ahmad Habibie Marjan
// Tanggal   : 7-9-2023
// Deskripsi : Pra-Praktikum 1-2. Program menerima input n bilangan bulat positif dan menampilkan output n baris dengan ketentuan

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