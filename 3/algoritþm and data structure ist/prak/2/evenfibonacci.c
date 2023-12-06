// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月15日
// Topik     : Praktikum 2 - Pengenalan C
// Deskripsi : Program menjumlahkan bilangan Fibonacci genap ke 1-n

#include <stdio.h>

/* Praktikum
int main() {
    int n, i, sum;
    int Fibonacci[50];
    Fibonacci[0] = 1;
    Fibonacci[1] = 1;
    for(i=2; i<50; i++) {
        Fibonacci[i]=Fibonacci[i-1]+Fibonacci[i-2];
    }
    for(i=0; i<50; i++) printf("%d ", Fibonacci[i]);
    printf("\n");
    scanf("%d", &n);
    while (n<=50 && n>=1) {
        sum=0;
        for(i=2; i<n; i++) if(Fibonacci[i]%2==0) sum+=Fibonacci[i];
        printf("%d\n", sum);
        scanf("%d", &n);
    }
    printf("-1\n");
    return 0;
}
*/

// Pascapraktikum

void nextFibonacci(long long int *a,long long int *b,long long int *c) {
    *a=*b;
    *b=*c;
    *c=*a+*b;
}

int isEven(long long int x) {
    return x%2==0;
}

int main() {
    long long int a=-1,b=1,c=0,s=0;
    int i,n;
    scanf("%d",&n);
    if(n>0 && n<51) {
        for(i=0;i<n;i++) {
            nextFibonacci(&a,&b,&c);
            if(isEven(c)) s+=c;
        }
        printf("%lld\n",s);
    }
    else printf("-1\n");
    return 0;
}