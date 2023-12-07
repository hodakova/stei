// 23-10-03

#include <stdio.h>

/* aidoru_shinetai - Tukarlah bit ke-1 dan bit ke-4 dari a
 * 
 * Contoh:
 *   aidoru_shinetai(0b1000)=0b0001
 *   aidoru_shinetai(0b0001)=0b1000
 *   aidoru_shinetai(0b1010)=0b0011
 *   aidoru_shinetai(0b0101)=0b1100
 * 
 * Legal ops : ~ & | + << >>
 * Max ops   : 15
 * Rating    :  2
 * 
 */
int aidoru_shinetai(int a) {
    return (a&~9)|((a&8)>>3)|((a&1)<<3);
}
// points :  2
// ops    :  8
// perf   :  2

int main() {
    int a;
    scanf("%d", &a);
    int x=aidoru_shinetai(a);
    printf("%d\n", x);
}