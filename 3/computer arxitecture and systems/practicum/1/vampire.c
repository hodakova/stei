// 23-10-03

#include <stdio.h>

/* vampire - Mengembalikan nilai dengan ketentuan: 
 *   Jika bit pada posisi yang sama pada kedua bilangan sama, maka
 *     bit tersebut bernilai 1
 *   Jika bit pada posisi yang sama pada kedua bilangan berbeda, maka
 *     bit tersebut akan bernilai 0
 * 
 * Contoh:
 *   vampire(0,0)=-1 karena bit sama semua jadi 0xFFFF_FFFF
 *   vampire(0,1)=-2 karena bit sama semua kecuali yang terakhir jadi 0xFFFF_FFFE
 *   vampire(0xFFFF0000,0x0000FFFF)=0 karena tiada bit yang sama
 *   vampire(0x0000000F,0xFFFFFFF8)=8 karena 0b1111 XNOR 0b1000 = 0b0111
 * 
 * Legal ops : ~ & | << >>
 * Max ops   :  8
 * Rating    :  1
 * 
 */
int vampire(int x, int y) {
    return (x&y)|(~x&~y);
}
// points :  2
// ops    :  5
// perf   :  2

int main() {
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    int x=vampire(a,b);
    printf("%d\n", x);
}