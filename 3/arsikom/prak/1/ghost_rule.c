// 23-10-04

#include <stdio.h>

/* ghost_rule - Mengembalikan 1 jika x merupakan 2^n dan
                Mengembalikan 0 jika tidak
                (n>=0)
 * 
 * Legal ops : ~ & | + << >>
 * Max ops   : 20
 * Rating    :  2
 * 
 */
int ghost_rule(int n) {
    return ~((n + ~0)>>31) &1& (((n & (n + ~0)) + ~0) >> 31);
}
// points :  2
// ops    : 12
// perf   :  2

int main() {
    int a;
    scanf("%d", &a);
    int x=ghost_rule(a);
    printf("%d\n", x);
}