// NIM_Nama  : 18222082_Ahmad Habibie Marjan
// Tanggal   : 7-9-2023
// Deskripsi : Pra-Praktikum 1-3. Program menerima input n bilangan bulat positif dan menampilkan hasil kali seluruh non zero digit dari n dan jumlah non zero digit dari x

#include <stdio.h>

int main() {
    long n, x = 1, count = 0; // n = integer positif, x = hasil kali seluruh non zero digit dari n, count = jumlah non zero digit dari x
    scanf("%ld", &n);
    while(n>=1)
    {
        if(n%10!=0) x = x*(n%10);
        n = n/10;
    }
    printf("%ld ", x);
    while(x>=1)
    {
        if(x%10!=0) count = count+1;
        x = x/10;
    }
    printf("%ld\n", count);
    return 0;
}