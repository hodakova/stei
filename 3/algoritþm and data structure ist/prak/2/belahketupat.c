// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月12日
// Topik     : Prapraktikum 2
// Deskripsi : Program membuat belah ketupat dengan panjang sisi miring N

#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        for(j=n-i; j>=1; j--)
            printf(" ");
        for(j=1; j<=2*i-1; j++)
            printf("*");
        printf("\n");
    }
    if (n>1) {
        for(i=n; i>=1; i--) {
            for(j=n-i; j>=1; j--)
                printf(" ");
            for(j=1; j<=2*i-1; j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}