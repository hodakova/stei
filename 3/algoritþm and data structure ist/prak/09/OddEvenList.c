// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月09日
// Topik     : Prapraktikum 9
// Deskripsi : Program implementasi OddEvenList.h

#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even)
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
{
    List Lsort;
    address P, Q, Qrec, tmp;
    boolean found;

    // copy sort
    CreateEmpty(&Lsort);
    P = First(L);
    while(P != Nil) {
        if(IsEmpty(Lsort))
            InsVFirst(&Lsort, Info(P));
        else {
            Qrec = Nil;
            Q = First(Lsort);
            found = false;
            while(Q != Nil && !found) {
                if(Info(Q) < Info(P))
                    found = true;
                else {
                    Qrec = Q;
                    Q = Next(Q);
                }
            }
            if(Qrec == Nil)
                InsVFirst(&Lsort, Info(P));
            else {
                tmp = Alokasi(Info(P));
                if(tmp != Nil)
                    InsertAfter(&Lsort, tmp, Qrec);
            }
        }
        P = Next(P);
    }

    // divide
    CreateEmpty(Odd);
    CreateEmpty(Even);
    Qrec = First(Lsort);
    Q = Next(Qrec);
    while(Qrec != Nil) {
        if(Info(Qrec) % 2 == 1)
            InsertFirst(Odd, Qrec);
        else
            InsertFirst(Even, Qrec);
        Qrec = Q;
        if(Q != Nil)
            Q = Next(Q);
    }
}
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/