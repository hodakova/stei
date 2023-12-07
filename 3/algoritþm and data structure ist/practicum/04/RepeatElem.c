// NIM             : 18222082
// Nama            : Ahmad Habibie Marjan
// Tanggal         : 23年09月29日
// Topik praktikum : Praktikum 4
// Deskripsi       : Program implementasi RepeatElem.h

#include "RepeatElem.h"

/*
Fungsi RepeatElem menerima satu buah argumen, yaitu sebuah pointer ke list L yang akan diperiksa bila ada anggotanya yang berulang.
Fungsi ini akan menghapus setiap pengulangan anggota yang sama pada L (jika ada) dan akan mengembalikan sebuah list baru L2 yang berisi
setiap anggota yang berulang tersebut (jika ada).
Jika ada anggota yang berulang lebih dari satu kali pada L, maka cukup isikan anggota tersebut satu kali saja ke L2 sehingga tidak ada
anggota yang berulang pada L2
*/
List RepeatElem(List *L) {
    int i = 1, j, v;
    boolean found;
    List L2 = MakeList();

    while(i < Length(*L)) {
        v = Get(*L, i);
        j = 0, found = false;
        while(j < i && !found) {
            if(Get(*L, j) == v) {
                found = true;
                if(!Search(L2, v))
                    InsertLast(&L2, v);
                DeleteAt(L, i);
            }
            else
                j ++;
        }
        if(!found)
            i ++;
    }
    return L2;
}