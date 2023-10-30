// 23-10-03

#include <stdio.h>

/* sharuru - Menggabungkan representasi biner dua integer dengan ketentuan:
 *   bit ke-1 sampai ke-4 akan diambil dari bit ke-1 sampai ke-4 x
 *   bit ke-5 sampai ke-8 akan diambil dari bit ke-5 sampai ke-8 y
 *   bit sisanya akan bernilai 0
 * 
 * Contoh:
 *   sharuru(0xFF, 0x00) = 0x0F
 *   sharuru(0x00, 0xFF) = 0xF0
 *   sharuru(0x12, 0xAB) = 0xA2
 *   sharuru(0xF0, 0x12) = 0x10
 * 
 * Legal ops : ~ & | << >>
 * Max ops   :  3
 * Rating    :  1
 * 
 */
int sharuru(int x, int y) {
    return (0x0F&x)|(0xF0&y);
}
// points :  2
// ops    :  3
// perf   :  2

int main() {
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    int x=sharuru(a,b);
    printf("%d\n", x);
}