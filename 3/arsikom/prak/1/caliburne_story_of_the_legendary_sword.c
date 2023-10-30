// 23-10-05

#include <stdio.h>

/* caliburne story of the legendary sword - Mengembalikan ceil(x*5/128) dengan ketentuan:
 *   pembagian yang digunakan adalah pembagian real
 *   ceil(x) menghasilkan bilangan bulat terkecil yang >= x
 *
 * Legal ops : Unsigned, & | ! + >>
 * Max ops   : 18
 * Rating    :  4
 * 
 */
unsigned caliburne_story_of_the_legendary_sword(unsigned x) {
    int a = x & 0x7F;
    int b = !!a;
    a = (a + a + a + a + a) >> 7;
    x = x >> 7;
    x = x + x + x + x + x;
    return x + a + b;
}
// points :  4
// ops    : 15
// perf   :  2

int main() {
    unsigned a;
    scanf("%d", &a);
    unsigned x=caliburne_story_of_the_legendary_sword(a);
    printf("%d\n", x);
}