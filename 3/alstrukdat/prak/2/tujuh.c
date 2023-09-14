// NIM             : 18222082
// Nama            : Ahmad Habibie Marjan
// Tanggal         : 14-09-23
// Topik praktikum : Praktikum 2 2022
// Deskripsi       : Menjumlahkan bilangan yg bisa dibagi 7 atau yg berdigit 7 pada rentang 1-m sebanyak n kali

#include <stdio.h>

int main() {
    int n, m, i, j, temp, sum;
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        scanf("%d", &m);
        sum=0;
        for (j=1; j<=m; j++) {
            if (j%7==0) sum+= j;
            else {
                temp=j;
                while (temp>0) {
                    if (temp%10==7) {
                        sum+=j;
                        break;
                    }
                    temp/=10;
                } 
            }
        }
        printf("%d\n", sum);
    }
}