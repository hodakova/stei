// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月27日
// Topik     : Praktikum 7
// Deskripsi : Program implementasi krabbypatty.h

#include "krabbypatty.h"

void krabbyPatty(Stack *ingredients, Stack *burger)
/*
Membuat satu Krabby Patty dari tumpukan bahan
*/
{
    Stack isi;
    CreateEmpty(&isi);

    infotype bahan;
    /*
    0 - roti bawah
    1 - patty
    2 - keju
    3 - selada
    4 - bawang
    5 - acar
    6 - tomat
    7 - saus
    8 - mustard
    9 - roti atas
    */

    boolean foundAtas = false, foundBawah = false;

    while((!foundAtas || !foundBawah) && !IsEmpty(*ingredients)) {
        Pop(ingredients, &bahan);
        if(bahan == 9)
            foundAtas = true;
        else if(bahan == 0)
            foundBawah = true;
        else
            Push(&isi, bahan);
    }

    if(foundAtas && foundBawah) {
        Push(burger, 0);
        while(!IsEmpty(isi)) {
            Pop(&isi, &bahan);
            Push(burger, bahan);
        }
        Push(burger, 9);
    }

}
/*
~ CONTOH 1 ~
Awal:
ingredients -> [7, 1, 9, 2, 3, 4, 3, 0, 1, 2]
burger -> []

Akhir:
ingredients -> [7, 1]
burger -> [0, 2, 3, 4, 3, 1, 2, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- keju
- patty
- selada
- bawang
- selada
- keju
- roti bawah

Sisa bahan di tumpukan bahan:
- patty
- saus

~ CONTOH 2 ~
Awal:
ingredients -> [0, 2, 9, 3, 4, 3, 7, 0, 9, 9]
burger -> []

Akhir:
ingredients -> [0, 2, 9, 3, 4, 3, 7]
burger -> [0, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- roti bawah

Sisa bahan di tumpukan bahan:
- saus
- selada
- bawang
- selada
- roti atas
- keju
- roti bawah

~ CONTOH 3 ~
Awal:
ingredients -> [1, 3, 8, 5, 7, 9]
burger -> []

Akhir:
ingredients -> []
burger -> []

Terjemahan:
Krabby Patty tidak dapat dibuat

Tidak ada bahan tersisa di tumpukan bahan
*/