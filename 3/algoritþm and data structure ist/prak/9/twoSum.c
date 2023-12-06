// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月10日
// Topik     : Praktikum 9
// Deskripsi : Program implementasi twoSum.h

#include "twoSum.h"
#include <stdio.h>

int twoSum(List L1, List L2)
/* I.S. Masing-masing elemen dari L1 dan L2 merupakan angka dan */
/* L1 maupun L2 tidak kosong */
/* F.S. Menghasilkan angka hasil penjumlahan dua buah list L1 dan L2 */
{
    address P1 = First(L1), P2 = First(L2);
    int A1 = 0, A2 = 0, x = 1;

    while(P1 != Nil) {
        A1 += Info(P1) * x;
        x *= 10;
        P1 = Next(P1);
    }

    x = 1;
    while(P2 != Nil) {
        A2 += Info(P2) * x;
        x *= 10;
        P2 = Next(P2);
    }

    return A1 + A2;
}
/* Contoh */
/* L1 = 1 -> 2 -> 3  = 321 */ 
/* L2 = 5 -> 4 = 45 */
/* maka hasilnya adalah */
/* 321 + 45 = 366 */

/* L1 = 1 -> 9 -> 9 */
/* L2 = 9 */
/* maka hasilnya adalah */
/* 991 + 9 = 1000 */