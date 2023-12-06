// 23-10-05

#include <stdio.h>

/* pandora paradoxxx - Mengembalikan hasil pembagian ke bawah x/196
 *
 * Contoh:
 *   pandora_paradoxxx(1000)=5
 * 
 * Legal ops : Konstanta besar, unsigned, & | ^ ! << >> ~ + *
 * Max ops   : 20
 * Rating    :  5
 * 
 */
int pandora_paradoxxx(int x) {
    return x/196;
}
// points :  
// ops    :  
// perf   :  

int main() {
    int a;
    scanf("%d", &a);
    int x=pandora_paradoxxx(a);
    printf("%d\n", x);
}