// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月17日
// Topik     : Praktikum 10
// Deskripsi : Program implementasi setlist.h

#include "setlist.h"

/* ********* Prototype ********* */

address Alokasi (infotype Elmt)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=Elmt, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;

    P = (address) malloc (sizeof(ElmtSet));
    if (P != Nil) {
        Info(P) = Elmt;
        Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
/* *** Konstruktor/Kreator *** */
{
    free(*P);
}
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong */
{
    First(*S) = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
{
    return First(S) == Nil;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen terakhir Set S. */
/* I.S. S mungkin kosong
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota terakhir dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if(!IsMember(*S, Elmt)) {
        address P = First(*S), Q = Alokasi(Elmt);
        // kurang kondisi isEmpty
        while(Next(P) != Nil) {
            P = Next(P);
        }

        Next(P) = Q;
    }
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    if(IsMember(*S, Elmt)) {
        address Prev = Nil, P = First(*S);
        while(Info(P) != Elmt) {
            Prev = P;
            P = Next(P);
        }
        if(Prev == Nil) {
            First(*S) = Next(P);
        }
        else {
            Next(Prev) = Next(P);
        }
        Dealokasi(&P);
    }
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    address P = First(S);
    while(P != Nil) {
        if(Info(P) == Elmt)
            return true;
        P = Next(P);
    }
    return false;
}

int Count(Set S)
/* Mengembalikan jumlah elemen/anggota di dalam S*/
{
    address P = First(S);
    int count = 0;
    while(P != Nil) {
        count ++;
        P = Next(P);
    }
    return count;
}