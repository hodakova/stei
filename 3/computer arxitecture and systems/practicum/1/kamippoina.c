// 23-10-03

#include <stdio.h>

/* kamippoina - Mengembalikan nilai sigma 0->x 2^x
 *
 * Contoh:
 *   kamippoina(4)=31
 *   0100->0001 1111
 *   kamippoina(2)= 7
 *   0010->0000 0111
 * 
 * Legal ops : ! + ~ & ^ | << >>
 * Max ops   :  6
 * Rating    :  1
 * 
 */
int kamippoina(int n) {
    return (1<<(n+1))+(~0);
}
// points :  2
// ops    :  4
// perf   :  2

int main() {
    int a;
    scanf("%d", &a);
    int x=kamippoina(a);
    printf("%d\n", x);
}