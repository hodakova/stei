// 23-10-04

#include <stdio.h>

/* bitter_choco_decoration - Mengembalikan nilai x*23
 * 
 * Contoh:
 *   bitter_choco_decoration(  1) =    23
 *   bitter_choco_decoration( 23) =   529
 *   bitter_choco_decoration(-69) = -1587
 * 
 * Legal ops : ! ~ & ^ | + << >>
 * Max ops   :  7
 * Rating    :  2
 * 
 */
int bitter_choco_decoration(int x) {
    return (x<<4)+(x<<2)+(x<<1)+x;
}
// points :  2
// ops    :  6
// perf   :  2

int main() {
    int a;
    scanf("%d", &a);
    int x=bitter_choco_decoration(a);
    printf("%d\n", x);
}