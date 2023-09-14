// NIM             : 18222082
// Nama            : Ahmad Habibie Marjan
// Tanggal         : 12-09-23
// Topik praktikum : Praktikum 2 2022
// Deskripsi       : Program membalikkan angka integer positif

#include <stdio.h>

/*
int main() {
	int angka;
	scanf("%d", &angka);
	while (angka > 9) {
		printf("%d", angka % 10);
		angka /= 10;
	}
	printf("%d\n", angka);
	return 0;
}
*/

int main() {
    int num, res=0, x10=1, temp;
    scanf("%d", &num);
    temp=num;
    while (temp>10) {
        x10*=10;
        temp/=10;
    }
    while (num>0) {
        res+=num%10*x10;
        num/=10;
        x10/=10;
    }
    printf("%d\n", res);
    return 0;
}