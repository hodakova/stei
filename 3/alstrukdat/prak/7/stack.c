// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月24日
// Topik     : Prapraktikum 7
// Deskripsi : Program implementasi stack.h

#include "stack.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == Nil;
}

boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return Top(S) == MaxEl -1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */
{
    if(IsEmpty(*S))
        Top(*S) = 0;
    else
        Top(*S) ++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    if(Top(*S) == 0)
        CreateEmpty(S);
    else
        Top(*S) --;
}