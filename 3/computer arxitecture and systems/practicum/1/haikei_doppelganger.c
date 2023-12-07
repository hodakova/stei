// 23-10-05

#include <stdio.h>

/* haikei doppelganger - Memeriksa apakah setiap word dalam x merupakan huruf dalam representasi ASCII
 * 
 * Contoh:
 *   haikei_doppelganger(0x62797465) = 1
 *   haikei_doppelganger(0x6D696B75) = 1
 *   haikei_doppelganger(0xFF797465) = 0
 *   haikei_doppelganger(0xFFFFFFFF) = 0
 * 
 * Legal ops : ! ~ & ^ | + << >>
 * Max ops   : 60
 * Rating    :  3
 * 
 */
int haikei_doppelganger(int x) {
    int neguppeA = ~0x40;
    int neguppeZ = ~0x5A;
    int neglowea = ~0x60;
    int neglowez = ~0x7A;

    int charact1 = x & 0xFF;
    int charact2 = (x >>  8) & 0xFF;
    int charact3 = (x >> 16) & 0xFF;
    int charact4 = (x >> 24) & 0xFF;

    int check1uA = (charact1 + neguppeA) >> 31;
    int check1uZ = (charact1 + neguppeZ) >> 31;
    int check1la = (charact1 + neglowea) >> 31;
    int check1lz = (charact1 + neglowez) >> 31;

    int check2uA = (charact2 + neguppeA) >> 31;
    int check2uZ = (charact2 + neguppeZ) >> 31;
    int check2la = (charact2 + neglowea) >> 31;
    int check2lz = (charact2 + neglowez) >> 31;

    int check3uA = (charact3 + neguppeA) >> 31;
    int check3uZ = (charact3 + neguppeZ) >> 31;
    int check3la = (charact3 + neglowea) >> 31;
    int check3lz = (charact3 + neglowez) >> 31;

    int check4uA = (charact4 + neguppeA) >> 31;
    int check4uZ = (charact4 + neguppeZ) >> 31;
    int check4la = (charact4 + neglowea) >> 31;
    int check4lz = (charact4 + neglowez) >> 31;

    int resultc1 = (check1uA ^ check1uZ) | (check1la ^ check1lz);
    int resultc2 = (check2uA ^ check2uZ) | (check2la ^ check2lz);
    int resultc3 = (check3uA ^ check3uZ) | (check3la ^ check3lz);
    int resultc4 = (check4uA ^ check4uZ) | (check4la ^ check4lz);

    return !~(resultc1 & resultc2 & resultc3 & resultc4);
}
// points :  3
// ops    : 60
// perf   :  2

int main() {
    int a;
    scanf("%d", &a);
    int x=haikei_doppelganger(a);
    printf("%d\n", x);
}