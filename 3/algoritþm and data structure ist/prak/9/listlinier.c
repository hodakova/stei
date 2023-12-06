// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月07日
// Topik     : Prapraktikum 9
// Deskripsi : Program implementasi listlinier.h

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address)malloc(sizeof(ElmtList));
    if(P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    boolean found = false;
    address P = First(L);
    while(P != Nil && !found) {
        if(Info(P) == X)
            found = true;
        else
            P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    if(P != Nil)
        InsertFirst(L, P);
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);
    if(P != Nil)
        InsertLast(L, P);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(IsEmpty(*L))
        InsertFirst(L, P);
    else {
        address last = First(*L);
        while(Next(last) != Nil)
            last = Next(last);
        InsertAfter(L, P, last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L, X), Prec = First(*L);
    if(P != Nil) {
        if(Prec == P)
            DelFirst(L, &P);
        else {
            while(Next(Prec) != P)
                Prec = Next(Prec);
            DelAfter(L, &P, Prec);
        } 
        Dealokasi(&P);
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address Prec = Nil, last = First(*L);
    while(Next(last) != Nil) {
        Prec = last;
        last = Next(last);
    }
    *P = last;
    if(Prec == Nil) // P merupakan address element pertama
        First(*L) = Nil;
    else
        Next(Prec) = Nil;

}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if(Next(Prec) != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
{
    address P = First(L);
    printf("[");
    while(P != Nil) {
        if(P != First(L))
            printf(",");
        printf("%d", Info(P));
        P = Next(P);
    }
    printf("]\n");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    address P = First(L);
    while(P != Nil) {
        count ++;
        P = Next(P);
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    return Info(AdrMax(L));
}
address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    address P = First(L), M = First(L);
    while(Next(P) != Nil) {
        P = Next(P);
        if(Info(P) > Info(M))
            M = P;
    }
    return M;
}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    return Info(AdrMin(L));
}
address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    address P = First(L), M = First(L);
    while(Next(P) != Nil) {
        P = Next(P);
        if(Info(P) < Info(M))
            M = P;
    }
    return M; 
}
float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    address P = First(L);
    int count = 0, sum = 0;
    while(P != Nil) {
        count ++;
        sum += Info(P);
        P = Next(P);
    }
    return (float)sum/count;
}

/****************** PROSES TERHADAP LIST ******************/
void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P = First(*L), Prec = Nil, loc;
    Prec = Next(P);
    while(Prec != Nil) {
        loc = Prec;
        Prec = Next(Prec);
        InsertFirst(L, loc);
        Next(P) = Prec;
    }
}
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmpty(L3);
    if(IsEmpty(*L1))
        First(*L3) = First(*L2);
    else {
        address lastL1 = First(*L1);
        First(*L3) = First(*L1);
        while(Next(lastL1) != Nil)
            lastL1 = Next(lastL1);
        Next(lastL1) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}