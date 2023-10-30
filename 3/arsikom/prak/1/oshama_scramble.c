// 23-10-05

#include <stdio.h>

/* oshama scramble - Mengembalikan bit-level equivalent dari ekspresi (int) f
 *   argumen f merupakan representasi bit dari bilangan desimal dalam bentuk single-precision floating point
 *   jika nilai float melebihi batasan (termasuk NaN dan infinity), kembalikan 0x80000000u
 *
 * Contoh:
 *   oshama_scramble(32.0)        = 32
 *   oshama_scramble(-420.69)     = -420
 *   oshama_scramble(0.000026)    = 0
 *   oshama_scramble(88888888888) = max int
 * 
 * Legal ops : semua operasi int/unsigned termasuk ||, &&. juga if, while
 * Max ops   : 30
 * Rating    :  4
 * 
 */
unsigned oshama_scramble(unsigned uf) {
    return 2;
}
// points :  2
// ops    : 12
// perf   :  2

int main() {
    unsigned a;
    scanf("%d", &a);
    unsigned x=oshama_scramble(a);
    printf("%d\n", x);
}