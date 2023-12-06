// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月29日
// Topik     : Prapraktikum 4
// Deskripsi : Program implementasi deret.h

#include "deret.h"
#include <math.h>

// Menerima argumen sebuah integer a, b dan n dimana a adalah nilai
// awal deret dan b adalah beda, kemudian 
// mengembalikan nilai deret aritmatika ke-n 
// Contoh:
// aritmatika(10, 10, 5) -> 50
int aritmatika(int a, int b, int n) {
    int res=a+b*(n-1);
    return res;
}

// Menerima argumen sebuah integer a, r dan n dimana a adalah nilai
// awal deret dan r adalah rasio, kemudian 
// mengembalikan nilai deret geometri ke-n 
// Contoh:
// geometri(10, 2, 5) -> 160
int geometri(int a, int r, int n) {
    int res=a*pow(r,n-1);
    return res;
}

// Menerima argumen sebuah integer a, b dan n dimana a adalah nilai
// awal deret dan b adalah beda, kemudian 
// mengisi nilai result dari U1 hingga Un
// Contoh deret_aritmatika(10, 10, 5) maka
// nilai result = [10, 20, 30, 40, 50]
void deret_aritmatika(int a, int b, int n, int *result) {
    for(int i=0;i<n;i++) *(result+i)=aritmatika(a,b,i+1);
}

// Menerima argumen sebuah integer a, r dan n dimana a adalah nilai
// awal deret dan r adalah rasio, kemudian 
// mengisi nilai result dari U1 hingga Un
// Contoh deret_geometri(10, 2, 5) maka
// nilai result = [10, 20, 40, 80, 160]
void deret_geometri(int a, int r, int n, int *result) {
    for(int i=0;i<n;i++) *(result+i)=geometri(a,r,i+1);
}

// Menerima argumen sebuah integer n, kemudian 
// mengisi nilai result dari segitiga pascal baris ke-n
// Contoh n = 5, result akan bernilai = [1, 4, 6, 4, 1]
void segitiga_pascal(int n, int *result) {
    int i,j;
    int *pascal=(int*)malloc(sizeof(int)*n);
    int *pascalprev=(int*)malloc(sizeof(int)*n);
    
    if(n>0) {
        for(i=1;i<=n;i++) {
            for(j=0;j<=i;j++) {
                if(j==0||j==i-1) pascal[j]=1;
                else pascal[j]=pascalprev[j-1]+pascalprev[j];
            }
            for(j=0;j<=i;j++) pascalprev[j]=pascal[j];
        }
    }
    for(i=0;i<n;i++) *(result+i)=pascal[i];
}