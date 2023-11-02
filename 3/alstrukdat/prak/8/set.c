// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月03日
// Topik     : Prapraktikum 8
// Deskripsi : Program implementasi set.h

#include "set.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    (*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if(!IsMember(*S, Elmt)) {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count ++;
    }
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    int i = 0;
    while(i < (*S).Count) {
        if((*S).Elements[i] == Elmt) {
            (*S).Elements[i] = (*S).Elements[(*S).Count-1];
            (*S).Count --;
            break;
        }
        else
            i ++;
    }
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    int i = 0;
    boolean found = false;
    while(i < S.Count && !found) {
        if(S.Elements[i] == Elmt)
            found = true;
        else
            i ++;
    }
    return found;
}