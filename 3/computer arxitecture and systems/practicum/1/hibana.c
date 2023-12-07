// 23-10-04

#include <stdio.h>

/* hibana - Mengembalikan nilai tertinggi dari 3 input integer
 * a, b, c >= 0
 * 
 * Contoh:
 *   hibana( 1, 9, 5) =  9
 *   hibana(10, 3, 5) = 10
 * 
 * Legal ops : ! ~ & | + << >>
 * Max ops   : 20
 * Rating    :  3
 * 
 */
int hibana(int a, int b, int c) {
    int cheque  = (a + ~b + 1) >> 31;
    int maxima  = (a & ~cheque) | (b & cheque);
    cheque = (maxima + ~c + 1) >> 31;
    maxima = (maxima & ~cheque) | (c & cheque);
    return cheque;
}
// points :  3
// ops    : 16
// perf   :  2

int main() {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    int x=hibana(a,b,c);
    printf("%d\n", x);
}