// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月15日
// Topik     : Praktikum 2 - Pengenalan C
// Deskripsi : Program mampilkan semua bilangan armstrong dari range a-b

#include <stdio.h>

int main() {
    int a,b,i,j,k,temp,count,pangkat,sum;
    scanf("%d %d", &a, &b);
    for(i=a; i<=b; i++) {
        temp=i;
        count=0;
        while(temp>0) {
            temp/=10;
            count+=1;
        }
        temp=i;
        sum=0;
        for(j=0; j<count; j++) {
            pangkat=1;
            for(k=0; k<count; k++) pangkat*=temp%10;
            sum+=pangkat;
            temp/=10;
        }
        if(sum==i) printf("%d\n", i);
    }
    return 0;
}
