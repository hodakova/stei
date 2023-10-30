// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23-10-20
// Topik     : Prapraktikum 6
// Deskripsi : Program implementasi circular_queue.h

#include "circular_queue.h"
#include <stdio.h>


/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
{
    return IDX_HEAD(Q)==IDX_UNDEF && IDX_TAIL(Q)==IDX_UNDEF;
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
{
    boolean res;
    if(IDX_TAIL(Q)>=IDX_HEAD(Q))
        res = IDX_TAIL(Q)-IDX_HEAD(Q)==IDX_MAX;
    else
        res = IDX_HEAD(Q)-IDX_TAIL(Q)==1;
}

int Length (Queue Q)
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
{
    int res;
    if(IsEmpty(Q))
        res = 0;
    else if(IDX_TAIL(Q)>=IDX_HEAD(Q))
        res = IDX_TAIL(Q)-IDX_HEAD(Q)+1;
    else
        res = IDX_TAIL(Q)-IDX_HEAD(Q)+2+IDX_MAX;
    return res;
}


/* *** Kreator *** */
void CreateQueue (Queue * Q)
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */
{
    IDX_HEAD(*Q)=IDX_UNDEF;
    IDX_TAIL(*Q)=IDX_UNDEF;
}

/* *** Primitif Add/Delete *** */
void enqueue (Queue * Q, ElType X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
{
    if(IsEmpty(*Q)) {
        IDX_HEAD(*Q)=0;
        IDX_TAIL(*Q)=0;
    }
    else {
        IDX_TAIL(*Q)++;
        IDX_TAIL(*Q)%=IDX_MAX+1;
    }
    TAIL(*Q)=X;
}

ElType dequeue (Queue * Q)
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    ElType X = HEAD(*Q);
    if(IDX_HEAD(*Q)==IDX_TAIL(*Q)) {
        IDX_HEAD(*Q)=IDX_UNDEF;
        IDX_TAIL(*Q)=IDX_UNDEF;
    }
    else {
        IDX_HEAD(*Q)++;
        IDX_HEAD(*Q)%=IDX_MAX+1;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal dan mekanisme circular buffer;
/* Queue ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */
{
    printf("[");
    int i,l = Length(q);
    for(i=0;i<l;i++) {
        printf("%d",q.Tab[(i+IDX_HEAD(q))%(IDX_MAX+1)]);
        if(i<l-1)
            printf(",");
    }
    printf("]\n");
}