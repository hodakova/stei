// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月15日
// Topik     : Praktikum 2 - Pengenalan C
// Deskripsi : Program mencari bilangan terbesar kedua dari input

#include <stdio.h>

/* Praktikum
int main() {
    int n, i, j, temp;
    scanf("%d", &n);
    char arr[99];
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) if(arr[i]>arr[j] && i>j) {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    //for(i=0; i<n; i++) printf("%d", arr[i]);
    if(n>1) printf("%d\n", arr[1]);
    return 0
}
*/

// Pascapraktikum
int main() {
    int n,a,b=-999,x=-999;
    scanf("%d",&n);
    for(int i=0;i<n; i++) {
        scanf("%d",&a);
        if(a>b) {
            x=b;
            b=a;
        }
        else if(a>x && a!=b)
            x=a;
    }
    if(x==-999) printf("%d\n",a);
    else printf("%d\n",x);
    return 0;
}