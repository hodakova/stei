// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月08日
// Topik     : Praktikum 1
// Deskripsi : Program untuk menentukan bilangan palindrom prima ke-N

#include <stdio.h>

int power(int x,int n) {
    int r=1;
    for(int i=0;i<n;i++) r*=x;
    return r;
}

int isPrime(int x) {
    int r=0;
    if(x>1) r=1;
    for(int i=2;i<x;i++) {
        if(x%i==0) r=0;
    }
    return r;
}

int isPalindrom(int x) {
    int r=1,t=x,awwaal,awsat=x,akhiir,l=0;
    while(t>9) {
        t/=10;
        l++;
    }
    while(r && awsat>9) {
        akhiir=awsat%10;
        awsat/=10;
        l--;
        awwaal=awsat/power(10,l);
        awsat-=awwaal*power(10,l);
        l--;
        if(awwaal!=akhiir) r=0;
    }
    return r;
}

int palindprime(int n) {
    int x=0,i=1,palindrom=0,prime=0;
    while(i<=n) {
        x++;
        if(isPalindrom(x) && isPrime(x)) i++;
    }
    return x;
}

int main() {
    int n,r;
    scanf("%d",&n);
    r=palindprime(n);
    printf("%d\n",r);
    return 0;
}