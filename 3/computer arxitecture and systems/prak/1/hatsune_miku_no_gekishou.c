// 23-10-05

#include <stdio.h>

/* hatsune miku no gakishou - Mengembalikan hasil penambahan 2 integer, dengan ketentuan:
 *   jika terjadi overflow positif, kembalikan nilai maxint
 *   jika terjadi overflow negatif, kembalikan nilai minint
 * 
 * Contoh:
 *   hatsune_miku_no_gakishou(0x40000000, 0x40000000) = 0x7fffffff
 *   hatsune_miku_no_gakishou(0x80000000, 0xffffffff) = 0x80000000
 * Legal ops : ! ~ ^ & | + << >>
 * Max ops   : 18
 * Rating    :  4
 * 
 */
int hatsune_miku_no_gakishou(int x, int y) {
    int isxneg = x >> 31;
    int isyneg = y >> 31;
    int summar = x + y;
    int issumn = summar >> 31;
    int limitt = 1 >> 31;
    int ovrflw = ~(isxneg ^ isyneg) & (isxneg ^ issumn);
    int result = (~ovrflw & summar) | (ovrflw & ((~isxneg & ~limitt) | (isxneg & limitt))); //8 ops
    return result;
}
// points :  4
// ops    : 18
// perf   :  2

int main() {
    int a=0;
    int b=0;
    scanf("%x", &a);
    scanf("%x", &b);
    int x=hatsune_miku_no_gakishou(a,b);
    printf("%x\n", x);
}