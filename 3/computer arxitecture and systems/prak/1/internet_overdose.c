// 23-10-05

#include <stdio.h>

/* internet overdose - Mengembalikan hasil shuffling terhadap bits dari x, dengan ketentuan:
 *   abcd efgh ijkl mnop ABCD EFGH IJKL MNOP -> aAbB cCdD eEfF gGhH iIjJ kKlL mMnN oOpP
 * 
 * Contoh:
 *   internet_overdose(0xFFFF_0000) = (0xAAAA_AAAA)
 * 
 * Legal ops : ! ~ & ^ | + << >>
 * Max ops   : 60
 * Rating    :  3
 * 
 */
int internet_overdose(int i) {
    int t = (i ^ (i >> 8)) & (0xFF << 8);
    i = i ^ t ^ (t << 8);
    t = (i ^ (i >> 4)) & (0xF  << 20 | 0xF  <<  4);
    i = i ^ t ^ (t << 4);
    t = (i ^ (i >> 2)) & (0x0C << 24 | 0x0C << 16 | 0x0C <<  8 | 0x0C);
    i = i ^ t ^ (t << 2);
    t = (i ^ (i >> 1)) & (0x22 << 24 | 0x22 << 16 | 0x22 <<  8 | 0x22); 
    i = i ^ t ^ (t << 1);
    return i;
}
// points :  3
// ops    : 40
// perf   :  2

int main() {
    int a;
    scanf("%d", &a);
    int x=internet_overdose(a);
    printf("%d\n", x);
}